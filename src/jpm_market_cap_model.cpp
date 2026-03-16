#include <iostream>

/**
 * JPM 2026: The 7,500 S&P Target
 * Lead Strategist: Dubravko Lakos-Bujas
 */
int main() {
    const int sp500_base_target = 7500;
    const int sp500_bull_target = 8000;
    double earnings_growth_forecast = 0.14; // 13-15% range

    std::cout << "--- JPMORGAN 2026 MARKET OUTLOOK ---" << std::endl;
    std::cout << "S&P 500 Base Target: " << sp500_base_target << std::endl;
    std::cout << "S&P 500 Bull Case:   " << sp500_bull_target << " (Conditional on Fed)" << std::endl;
    std::cout << "Earnings Momentum:   " << (earnings_growth_forecast * 100) << "%" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Note: AI 'FOBO' (Fear of Becoming Obsolete) driving capex." << std::endl;
    return 0;
}
