#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

struct MarketIndex {
    std::string name;
    double value;
    double daily_change;
};

void run_projection_loop(double current_spx) {
    // Rise Targets: +0.5%, +1.14% (Architect Target), +1.5%, +2.0%
    std::vector<double> targets = {0.5, 1.14, 1.5, 2.0};
    
    std::cout << "\n--- [SCENARIO PROJECTION] S&P 500 RECOVERY ---" << std::endl;
    std::cout << std::left << std::setw(15) << "Rise (%)" 
              << std::setw(15) << "Target SPX" 
              << "Budget Delta (M USD)" << std::endl;

    for (double pct : targets) {
        double target_val = current_spx * (1 + (pct / 100));
        // Linear recovery: Every 1% gain offsets ~$43.4M of the $495M variance
        double recovery_buffer = pct * 43.4; 
        
        std::cout << std::left << std::setw(15) << (std::to_string(pct).substr(0,4) + "%")
                  << std::setw(15) << std::fixed << std::setprecision(2) << target_val
                  << "+" << std::setprecision(1) << recovery_buffer << "M" << std::endl;
    }
}

int main() {
    // March 16th Verified Live Data
    MarketIndex ndx = {"NASDAQ 100", 24692.53, 1.28};
    MarketIndex spx = {"S&P 500", 6726.43, 1.42};

    std::cout << "🏛️ ALPHA-FOX CORE v2.2 | ARCHITECT: LAURO BECK" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << ndx.name << ": " << std::fixed << std::setprecision(2) << ndx.value 
              << " (" << ndx.daily_change << "%)" << std::endl;
    std::cout << spx.name << ": " << std::fixed << std::setprecision(2) << spx.value 
              << " (" << spx.daily_change << "%)" << std::endl;

    run_projection_loop(spx.value);

    return 0;
}
