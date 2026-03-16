# --- STAGE 1: BUILDER ---
FROM python:3.13-slim AS builder
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    g++ \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /app
# Mocking requirements if not present to avoid build failure
RUN touch requirements.txt
RUN pip install --no-cache-dir --target=/app/packages qiskit qiskit-ibm-runtime

# Compile C++ Engine
COPY src/ /app/src/
RUN mkdir -p /app/bin && \
    g++ -O3 -std=c++20 /app/src/fiscal_engine.cpp -o /app/bin/alpha_fox_suite

# --- STAGE 2: RUNTIME ---
FROM python:3.13-slim AS runtime
WORKDIR /app
COPY --from=builder /app/bin/alpha_fox_suite ./bin/alpha_fox_suite
COPY --from=builder /app/packages /usr/local/lib/python3.13/site-packages
COPY . .
ENV PYTHONPATH=/usr/local/lib/python3.13/site-packages
ENV PYTHONUNBUFFERED=1
ENTRYPOINT ["./run_lab.sh"]
