#include <iostream>
#include <iomanip>

/**
 * 2026 AI Infrastructure: The $1T Supercycle
 * Data: JPM Outlook 2026 (March 15 update)
 */
int main() {
    const double openai_capacity_gw = 25.0;
    const double cost_per_gw_b = 50.0; // JPM estimate: $50B per GW
    const double total_capex_t = (openai_capacity_gw * cost_per_gw_b) / 1000.0;
    
    // Financing Alpha: Banks targeting $870B in new debt for this sector
    double sector_debt_needs_b = 870.0;

    std::cout << "--- GLOBAL AI INFRASTRUCTURE (MAR-2026) ---" << std::endl;
    std::cout << "OpenAI Planned Capacity:  " << openai_capacity_gw << " GW" << std::endl;
    std::cout << "Total Estimated Capex:    $" << std::fixed << std::setprecision(2) << total_capex_t << " Trillion" << std::endl;
    std::cout << "Sector Debt Financing:    $" << sector_debt_needs_b << "B" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "STRATEGY: JPM/GS lead-arranging 'Stargate' debt tranches." << std::endl;
    
    return 0;
}
