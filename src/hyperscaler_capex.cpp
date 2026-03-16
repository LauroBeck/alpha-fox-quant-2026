#include <iostream>
#include <iomanip>

int main() {
    const double msft_capex_b = 105.0; // Microsoft (Fiscal year ending June)
    const double amzn_capex_b = 200.0; // Amazon 2026 Plan
    const double goog_capex_b = 185.0; // Alphabet/Google
    const double meta_capex_b = 135.0; // Meta Bull Case
    
    double total_big4_capex = msft_capex_b + amzn_capex_b + goog_capex_b + meta_capex_b;

    std::cout << "--- BIG TECH AI ARMS RACE (2026 GUIDANCE) ---" << std::endl;
    std::cout << "Microsoft:  $" << msft_capex_b << "B" << std::endl;
    std::cout << "Amazon:     $" << amzn_capex_b << "B" << std::endl;
    std::cout << "Google:     $" << goog_capex_b << "B" << std::endl;
    std::cout << "Meta:       $" << meta_capex_b << "B" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "TOTAL CAPEX: $" << total_big4_capex << "B (+60% YoY)" << std::endl;
    std::cout << "RISK: 45-57% of revenue is now capital intensive." << std::endl;
    return 0;
}
