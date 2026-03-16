import json
import os

# Verified Market Anchors: March 16, 2026
market_data = {
    "gold": 5013.21,
    "brent": 104.15,
    "vix": 27.19,
    "sp500": 6662.50,
    "jpm_budget": 19.8e9
}

def export_for_cpp():
    # Save as JSON for the C++ monitor to read
    os.makedirs('data', exist_ok=True)
    with open('data/market_snapshot.json', 'w') as f:
        json.dump(market_data, f)
    print(f"--- [PYTHON] Data Exported: Brent ${market_data['brent']} | Gold ${market_data['gold']} ---")

if __name__ == "__main__":
    export_for_cpp()
