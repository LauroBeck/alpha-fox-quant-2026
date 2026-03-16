#include <iostream>
#include <iomanip>

/**
 * Commodity Stress Test: March 15, 2026
 * Market: Brent $103.82 | Gold $5,023.10
 */
int main() {
    const double brent_price = 103.82;
    const double gold_spot = 5023.10;
    const double inflation_floor = 0.022; // BoK 2.2% target

    std::cout << "--- REAL-TIME COMMODITY STRESS TEST ---" << std::endl;
    std::cout << "Brent Crude: $" << brent_price << " (Hormuz Conflict Premium)" << std::endl;
    std::cout << "Spot Gold:   $" << gold_spot << " (Critical Support Floor)" << std::endl;
    
    // IMF logic: 10% oil hike (~$10) = +0.4% Inflation
    double cpi_risk_adj = ((brent_price - 80.0) / 10.0) * 0.004;

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Inflation Risk Adjustment: +" << std::fixed << std::setprecision(2) << (cpi_risk_adj * 100) << "%" << std::endl;
    std::cout << "Projected Effective CPI:   " << (inflation_floor + cpi_risk_adj) * 100 << "%" << std::endl;
    return 0;
}
