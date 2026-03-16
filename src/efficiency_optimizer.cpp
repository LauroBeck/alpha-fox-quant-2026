#include <iostream>
#include <iomanip>
#include <vector>

void run_efficiency_simulation(double daily_tax_millions) {
    // Tiers: [Base, Liquid, Photonic, Quantum, Sovereign]
    std::vector<double> efficiency_gains = {0.0, 0.15, 0.35, 0.65, 0.95};
    std::vector<std::string> tiers = {
        "Standard Air", 
        "Liquid Immersion", 
        "Photonic Interconnect", 
        "Quantum Scheduler",
        "Sovereign Tier (95%)"
    };

    std::cout << "\n🏛️ ARCHITECT: Lauro Beck | MISSION: Institutional Equilibrium" << std::endl;
    std::cout << "Targeting Daily Tax: -$" << daily_tax_millions << "M" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(25) << "Architecture Tier" 
              << std::setw(18) << "Savings (M)" 
              << "Remaining Tax (M)" << std::endl;

    for (size_t i = 0; i < tiers.size(); ++i) {
        double savings = daily_tax_millions * efficiency_gains[i];
        double remaining = daily_tax_millions - savings;
        
        // Print with negative signs to represent the cash flow reality
        std::cout << std::left << std::setw(25) << tiers[i] 
                  << "-$" << std::fixed << std::setprecision(1) << std::setw(16) << savings
                  << "-$" << remaining << "M" << std::endl;
    }
}

int main() {
    run_efficiency_simulation(45000.0);
    return 0;
}
