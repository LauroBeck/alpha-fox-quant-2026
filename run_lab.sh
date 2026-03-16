#!/bin/bash
# Master Orchestrator: Identity -> Market -> Quantum -> Git
echo "--- LAUROBECKDBA: 2026 LAB ORCHESTRATION ---"

# Step 1: Identity/ORCID Sync
cd ../architect-identity-nexus && ./lab_sync.sh
cd ../quantum-sovereign-alpha

# Step 2: Market Data Pull (Bloomberg Pulse)
python3 ../quant-flow-intelligence-2026/bloomberg_pulse.py

# Step 3: Sovereign Alpha Quantum Audit (Qiskit v2.3)
source quantum_env/bin/activate
python3 sovereign_alpha.py

# Step 4: Generate Markdown Audit
./deploy_audit.sh

# Step 5: Commit to Professional Portfolio
./commit_to_portfolio.sh

echo "--- 2026 DAILY SYNC COMPLETE ---"
