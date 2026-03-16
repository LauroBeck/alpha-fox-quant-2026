import yfinance as yf
import pandas as pd
from datetime import datetime

class BloombergPulse:
    def __init__(self):
        self.timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        self.tickers = {
            "NVDA": "Nvidia (AI Alpha)",
            "^GSPC": "S&P 500 (6699 Pulse)",
            "^IXIC": "NASDAQ Composite",
            "^VIX": "Volatility Index", "XLE": "Energy (AI Power Demand)", "XLK": "Technology (AI Factory)", "XLE": "Energy Sector (Data Centers)", "XLK": "Technology Sector (AI)"
        }

    def get_market_snapshot(self):
        print(f"--- Bloomberg Pulse Sync: {self.timestamp} ---")
        data_points = []
        
        for ticker, name in self.tickers.items():
            try:
                t = yf.Ticker(ticker)
                # Using the more stable .info for 2026 session data
                info = t.info
                
                # Fallback logic for price retrieval
                current = info.get('currentPrice') or info.get('regularMarketPrice') or t.fast_info['last_price']
                prev_close = info.get('previousClose') or t.fast_info['previous_close']
                
                # Calculate simple day change if YTD isn't available
                day_change = ((current - prev_close) / prev_close) * 100 if prev_close else 0
                
                print(f"{name:20} | Price: ${current:8.2f} | Day Δ: {day_change:+.2f}%")
                data_points.append({"Asset": name, "Price": current})
            except Exception as e:
                print(f"Skipping {ticker}: Key Mapping Error")
        
        return pd.DataFrame(data_points)
        df = pd.DataFrame(data_points)
        df.to_json("market_snapshot.json", orient="records")

    def log_breaking_news(self):
        news = [
            "Nvidia CEO Jensen Huang forecasts $1T AI chip revenue through 2027.",
            "Warburg Pincus weighing $2.5B+ sale of subprime lender Exeter Finance.",
            "Energy Pivot: Alaska Mat-Su Assembly veto on coal-powered AI data centers on hold."
        ]
        print("\n--- Breaking Intelligence Feed ---")
        for item in news:
            print(f"▶ {item}")

if __name__ == "__main__":
    pulse = BloombergPulse()
    pulse.get_market_snapshot()
    pulse.log_breaking_news()
