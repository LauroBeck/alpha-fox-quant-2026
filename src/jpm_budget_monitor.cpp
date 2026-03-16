#include <iostream>
#include <fstream>
#include <string>
#include "include/json.hpp" // Assumes you have a JSON header or use simple parsing

using json = nlohmann::json;

int main() {
    std::ifstream f("data/market_snapshot.json");
    if (!f.is_open()) {
        std::cerr << "Error: Run scripts/fetch_market.py first." << std::endl;
        return 1;
    }

    json data;
    f >> data;

    double brent = data["brent"];
    double budget = data["jpm_budget"];
    
    std::cout << "--- [ALPHA-FOX] LIVE EXECUTION ---" << std::endl;
    std::cout << "Verified Brent: $" << brent << "/bbl" << std::endl;
    
    // Logic: If Brent > $100, hardware CapEx increases by 2.5%
    double inflation_penalty = (brent > 100.0) ? 1.025 : 1.0;
    double adjusted_total = budget * inflation_penalty;

    std::cout << "JPM Base Budget: $" << (budget / 1e9) << "B" << std::endl;
    std::cout << "Inflation Adjusted: $" << (adjusted_total / 1e9) << "B" << std::endl;
    std::cout << "Budget Variance: " << ((adjusted_total - budget) / 1e6) << "M USD" << std::endl;

    return 0;
}
