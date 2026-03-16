#include <iostream>
#include <iomanip>

/**
 * Project Stargate: 2026 Financing Model
 * Data: JPM/MS Structured Finance Report (Mar 2026)
 */
int main() {
    const double total_capex_t = 1.25; 
    const double bank_debt_tranche_b = 870.0; // Total sector debt need
    const double jpm_lead_share_pct = 0.15;
    
    std::cout << "--- PROJECT STARGATE: FINANCING ALPHA ---" << std::endl;
    std::cout << "Total Project Capex:  $" << total_capex_t << " Trillion" << std::endl;
    std::cout << "Debt Market Appetite: $" << bank_debt_tranche_b << "B" << std::endl;
    
    double jpm_fee_income = (bank_debt_tranche_b * jpm_lead_share_pct) * 0.0075; // 75bps fee

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Estimated JPM Fee:    $" << std::fixed << std::setprecision(2) << (jpm_fee_income * 1000) << "M" << std::endl;
    std::cout << "Status: Structured JV for U.S. AI Campus (Deployment 2028)" << std::endl;
    return 0;
}
