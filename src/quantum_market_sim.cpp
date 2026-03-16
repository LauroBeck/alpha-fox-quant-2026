#include <iostream>
#include <fstream>
#include <iomanip>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    std::ifstream f("data/quantum_results.json");
    if (!f.is_open()) return 1;

    json q_data;
    f >> q_data;

    std::cout << "--- ALPHA-FOX | QUANTUM MARKET ANALYSIS ---" << std::endl;
    std::cout << "Architect: Lauro Beck | System: IBM Quantum v2026" << std::endl;
    std::cout << "Asset: " << q_data["asset"] << " | Target: $" << q_data["resistance_level"] << std::endl;
    
    double prob = q_data["breakout_probability"];
    std::cout << "Quantum Probability of Breakout: " << (prob * 100) << "%" << std::endl;

    if (prob > 0.70) {
        std::cout << ">> SIGNAL: BULLISH DIVERGENCE. Hedge Brent exposure with Gold longs." << std::endl;
    } else {
        std::cout << ">> SIGNAL: RESISTANCE HOLDING. Maintain current liquidity levels." << std::endl;
    }

    return 0;
}
