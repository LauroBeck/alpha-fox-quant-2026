#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

struct TechBudget {
    const double TOTAL_ANNUAL_BUDGET = 19.8e9;  // $19.8 Billion
    const double NII_TARGET = 104.5e9;          // $104.5 Billion
    double current_spend = 0.0;
    double infra_inflation_index = 1.0;
};

int main() {
    TechBudget jpm2026;
    std::cout << "--- [ALPHA-FOX] JPM TECH BUDGET MONITOR ---" << std::endl;
    std::cout << "Target NII: $104.5B | Tech CapEx: $19.8B" << std::endl;

    // Verified Anchors for March 16, 2026
    double v_gold = 5013.21;
    double v_brent = 104.15;
    double v_vix = 27.19;

    for (int q = 1; q <= 4; ++q) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        // Logic: Energy shocks (> $100 Brent) drive infrastructure cost overruns
        jpm.infra_inflation_index += (v_brent > 100.0) ? 0.025 : 0.01;
        double quarterly_spend = (jpm2026.TOTAL_ANNUAL_BUDGET / 4) * jpm.infra_inflation_index;
        jpm2026.current_spend += quarterly_spend;

        std::cout << "Q" << q << " Spend: $" << (quarterly_spend / 1e6) << "M | Market: Brent $" << v_brent << std::endl;
    }

    std::cout << "Final 2026 Projected Spend: $" << (jpm2026.current_spend / 1e9) << "B" << std::endl;
    return 0;
}
