#!/bin/bash
# 2026 Portfolio Commit Engine
# Identity: LauroBeckDBA | Target: Alpha-Fox-Quant-2026

REPORT_FILE="Daily_Sovereign_Alpha_$(date +%Y-%m-%d).md"

echo "--- 2026 ALPHA-FOX QUANT UPDATE START ---"

if [ -f "$REPORT_FILE" ]; then
    echo "Staging $REPORT_FILE for alpha-fox-quant-2026..."
    
    # Ensure the remote is correct (updating to the specific repo provided)
    git remote set-url origin https://github.com/LauroBeck/alpha-fox-quant-2026.git 2>/dev/null
    
    # Staging and committing
    git add "$REPORT_FILE"
    git commit -m "Audit: Sovereign Alpha [VIX -13.5% | NVDA $184.27] - $(date +'%Y-%m-%d')"
    
    echo "Pushing to alpha-fox-quant-2026..."
    git push origin main # Assuming 'main' is your primary branch
    
    echo "--- QUANT UPDATE COMPLETE ---"
    echo "Live URL: https://github.com/LauroBeck/alpha-fox-quant-2026"
else
    echo "Error: $REPORT_FILE not found. Run ./run_lab.sh first."
fi
