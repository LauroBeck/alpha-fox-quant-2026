import numpy as np

class RiskEngine:
    def __init__(self):
        self.brent_baseline = 80.0
        # Risk factor 2.0 due to active Kharg Island strikes & Hormuz closure
        self.risk_factor = 2.0 

    def get_war_premium(self, current_brent):
        return (current_brent - self.brent_baseline) * self.risk_factor

    def get_stargate_drag(self, current_brent):
        # 0.12% ROI drag per $1 over baseline on $1.25T CapEx
        return (current_brent - 80) * 0.0012 * 1250000 

if __name__ == "__main__":
    engine = RiskEngine()
    brent = 104.63
    print(f"🏛️ ARCHITECT: Lauro Beck | STATUS: Hormuz Blockade Level 5")
    print(f"Brent: ${brent} | War Premium: ${engine.get_war_premium(brent):.2f}")
    print(f"Daily Stargate Tax: -${engine.get_stargate_drag(brent):,.2f}M")
