#include <iostream>
#include <vector>
#include <iomanip>

struct ChipState {
    std::string architecture;
    int cpu_cores;
    double mem_bandwidth_tbs;
    double token_cost_reduction; // vs Blackwell
};

int main() {
    std::vector<ChipState> roadmap = {
        {"Blackwell (B200)", 72, 8.0, 1.0},
        {"Vera Rubin (R100)", 88, 22.0, 10.0}
    };

    std::cout << "\n🏛️ ARCHITECT: Lauro Beck | NVIDIA GTC 2026 VERIFIED" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << std::left << std::setw(20) << "ARCHITECTURE" 
              << "| CORES" << " | BW(TB/s)" << " | INF COST REDUCTION" << std::endl;

    for (const auto& chip : roadmap) {
        std::cout << std::left << std::setw(20) << chip.architecture 
                  << "| " << chip.cpu_cores << "    | " << std::fixed << std::setprecision(1) 
                  << chip.mem_bandwidth_tbs << "      | " << chip.token_cost_reduction << "x" << std::endl;
    }
    return 0;
}
