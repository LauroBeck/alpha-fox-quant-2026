#include <iostream>
#include <iomanip>

/**
 * AI Chip Export Alpha: March 2026 Record
 * Data: South Korea 10-Day Report (175.9% Surge)
 */
int main() {
    double chip_export_val_b = 7.588;
    double surge_pct = 175.9; 
    double total_export_b = 21.5;

    std::cout << "--- KOREA AI CHIP EXPORT TRACKER ---" << std::endl;
    std::cout << "10-Day Chip Revenue: $" << chip_export_val_b << "B" << std::endl;
    std::cout << "Year-over-Year Growth: " << surge_pct << "% (ALL-TIME HIGH)" << std::endl;
    
    double market_concentration = (chip_export_val_b / total_export_b) * 100;

    std::cout << "------------------------------------" << std::endl;
    std::cout << "Chip Sector Share:    " << std::fixed << std::setprecision(1) << market_concentration << "% of Total" << std::endl;
    std::cout << "Analysis: DRAM prices rising for 11 consecutive months." << std::endl;
    return 0;
}
