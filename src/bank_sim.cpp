#include <iostream>
#include <iomanip>

/**
 * UBS 2026: Conflict Volatility & Gold Alpha
 * Status: March 15 Flight from Risk
 */
int main() {
    double gold_spot = 5170.0;      // Current resilient floor
    double ubs_target_gold = 6200.0; 
    double ubs_ytd_drop = -22.4;    // Military conflict impact
    
    std::cout << "--- UBS RISK & COMMODITIES (MAR-2026) ---" << std::endl;
    std::cout << "UBS Share Perf YTD:     " << ubs_ytd_drop << "%" << std::endl;
    std::cout << "Gold Spot:              $" << gold_spot << "/oz" << std::endl;
    std::cout << "UBS 2026 Gold Target:   $" << ubs_target_gold << "/oz" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "HEDGE STATUS: Gold holding above $5,170 as conflict offset." << std::endl;
    
    return 0;
}
