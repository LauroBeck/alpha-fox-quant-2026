# --- STAGE 1: BUILDER ---
FROM python:3.13-slim AS builder

# Install system-level build tools for C++20
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    g++ \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Install Python dependencies
COPY requirements.txt .
RUN pip install --no-cache-dir --target=/app/packages qiskit qiskit-ibm-runtime

# Compile the C++ Fiscal Engine
COPY src/ /app/src/
RUN mkdir -p /app/bin && \
    g++ -O3 -std=c++20 /app/src/fiscal_engine.cpp -o /app/bin/alpha_fox_suite

# --- STAGE 2: RUNTIME ---
FROM python:3.13-slim AS runtime

WORKDIR /app

# Copy only the essentials from the builder
COPY --from=builder /app/bin/alpha_fox_suite ./bin/alpha_fox_suite
COPY --from=builder /app/packages /usr/local/lib/python3.13/site-packages

# Copy the orchestration logic and scripts
COPY run_lab.sh .
COPY *.py ./
COPY *.sh ./

# Environment configuration
ENV PYTHONPATH=/usr/local/lib/python3.13/site-packages
ENV PYTHONUNBUFFERED=1

# Identity Metadata
LABEL maintainer="LauroBeckDBA"
LABEL mission="EmploymentMission2026"

ENTRYPOINT ["./run_lab.sh"]
