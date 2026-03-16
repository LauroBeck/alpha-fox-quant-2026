import json
import os

# March 16, 2026: Brent $104.15 | Gold $5,013.21 | VIX 27.19
market_data = {
    "gold": 5013.21,
    "brent": 104.15,
    "vix": 27.19,
    "jpm_budget": 19.8e9,
    "nii_target": 104.5e9
}

def export():
    os.makedirs('data', exist_ok=True)
    with open('data/market_snapshot.json', 'w') as f:
        json.dump(market_data, f)
    print(f"--- [PYTHON] March 16 Snapshot: Brent ${market_data['brent']} ---")

if __name__ == "__main__":
    export()
