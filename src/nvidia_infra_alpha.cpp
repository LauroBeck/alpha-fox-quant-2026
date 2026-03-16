#include <iostream>
#include <iomanip>

int main() {
    double quarterly_dc_rev_b = 39.1; // Record Q1 FY2026 (Reported Mar 2026)
    double blackwell_growth_pct = 17.0; 
    double gpu_unit_price = 30000.0; // Avg H100/Blackwell cost

    std::cout << "--- NVIDIA INFRASTRUCTURE ALPHA (MAR-2026) ---" << std::endl;
    std::cout << "Data Center Revenue: $" << quarterly_dc_rev_b << "B (Record)" << std::endl;
    std::cout << "Blackwell Momentum:  +" << blackwell_growth_pct << "% Seq." << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "STRATEGY: Transition from chip supplier to full-stack AI Factory." << std::endl;
    return 0;
}
