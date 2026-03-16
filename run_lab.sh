#!/bin/bash
echo "--- LAUROBECKDBA: 2026 LAB ORCHESTRATION ---"
python3 deploy_audit.sh
python3 sovereign_alpha.py
python3 stargate_listener.py
./bin/alpha_fox_suite
python3 commit_to_portfolio.sh
echo "--- 2026 DAILY SYNC COMPLETE ---"
