/* * Project: Alpha-Fox Quant Suite 2026
 * Lead Architect: Lauro Beck
 * Location: Rio de Janeiro, Brazil
 * Status: March 16, 2026 | Brent $104.15 | Gold $5,013.21
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "json.hpp" // Now looking directly in Lauro's include/ folder

using json = nlohmann::json;

int main() {
    std::ifstream f("data/market_snapshot.json");
    if (!f.is_open()) {
        std::cout << "[!] Market data missing. Run scripts/fetch_market.py" << std::endl;
        return 1;
    }

    json data;
    f >> data;

    double brent = data["brent"];
    double budget = data["jpm_budget"];
    
    std::cout << "--- ALPHA-FOX MONITOR | ARCHITECT: LAURO BECK ---" << std::endl;
    std::cout << "Verified March 16 Brent: $" << brent << "/bbl" << std::endl;
    
    // 2.5% Hardware inflation penalty triggered by Brent > $100
    double adjusted_total = (brent > 100.0) ? (budget * 1.025) : budget;

    std::cout << "JPM Tech Budget: $" << (budget / 1e9) << "B" << std::endl;
    std::cout << "Adjusted for Supply Shock: $" << (adjusted_total / 1e9) << "B" << std::endl;
    std::cout << "Variance to NII Target: " << ((adjusted_total - budget) / 1e6) << "M USD" << std::endl;

    return 0;
}
