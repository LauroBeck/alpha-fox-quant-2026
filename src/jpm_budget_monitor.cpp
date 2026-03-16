#include <iostream>
#include <iomanip>
#include <vector>

struct MarketState {
    double gold = 5013.21;
    double brent = 104.15;
    double vix = 27.19;
};

int main() {
    MarketState m16;
    const double JPM_TECH_BUDGET = 19.8e9;
    const double STARGATE_PHASE_1 = 125.0e9; // Part of the $1.25T total
    
    std::cout << "--- [ALPHA-FOX] JPM & STARGATE ARCHITECTURE MONITOR ---" << std::endl;
    std::cout << "Location: Rio de Janeiro | Time: March 16, 2026" << std::endl;
    std::cout << "Market Anchor: Brent Crude $" << m16.brent << " (Hormuz Premium Active)" << std::endl;

    double cumulative_spend = 0;
    double hardware_cost_multiplier = (m16.brent > 100.0) ? 1.025 : 1.0;

    std::cout << "\n[FISCAL PROJECTION]" << std::endl;
    for(int q=1; q<=4; q++) {
        double q_spend = (JPM_TECH_BUDGET / 4) * hardware_cost_multiplier;
        cumulative_spend += q_spend;
        std::cout << " Q" << q << " Projected CapEx: $" << std::fixed << std::setprecision(2) << (q_spend/1e6) << "M" << std::endl;
    }

    double variance = ((cumulative_spend - JPM_TECH_BUDGET) / JPM_TECH_BUDGET) * 100;
    std::cout << "\nFinal 2026 Variance: " << variance << "%" << std::endl;
    if(variance > 2.0) std::cout << ">> WARNING: Supply chain inflation exceeding NII buffer." << std::endl;

    return 0;
}
