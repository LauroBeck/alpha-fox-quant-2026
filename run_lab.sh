#!/bin/bash
echo "--- LAUROBECKDBA: 2026 CONTAINER ORCHESTRATION ---"
# Check if the C++ engine exists before running
if [ -f "./bin/alpha_fox_suite" ]; then
    ./bin/alpha_fox_suite
else
    echo "Error: Fiscal Engine binary not found."
fi
# Keep the container alive for auditing
tail -f /dev/null
