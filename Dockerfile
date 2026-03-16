# STAGE 1: The Builder (C++ and Python Dependencies)
FROM python:3.13-slim AS builder

# Install system-level build tools for C++20 and Python extensions
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    g++ \
    git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Install Python dependencies into a virtual environment for portability
COPY requirements.txt .
RUN python -m venv /opt/venv
ENV PATH="/opt/venv/bin:$PATH"
RUN pip install --no-cache-dir -r requirements.txt

# Compile the C++ Fiscal Engine
COPY . .
RUN mkdir build && cd build && \
    cmake .. && \
    make -j$(n_local) && \
    cp bin/alpha_fox_suite /app/alpha_fox_suite_binary

# STAGE 2: The Runtime (Lean Production Image)
FROM python:3.13-slim AS runtime

WORKDIR /app

# Copy the virtual environment and compiled binary from the builder
COPY --from=builder /opt/venv /opt/venv
COPY --from=builder /app/alpha_fox_suite_binary /app/alpha_fox_suite
COPY --from=builder /app/run_lab.sh /app/run_lab.sh
COPY --from=builder /app/sovereign_alpha.py /app/sovereign_alpha.py

# Set environment paths
ENV PATH="/opt/venv/bin:$PATH"
ENV PYTHONUNBUFFERED=1

# Final Identity/Audit configuration
LABEL maintainer="LauroBeckDBA"
LABEL project="Alpha-Fox-Quant-2026"

# Execute the orchestrator
ENTRYPOINT ["./run_lab.sh"]
