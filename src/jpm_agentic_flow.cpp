#include <iostream>
#include <iomanip>

/**
 * JPM 2026: Tech Spend vs NII Momentum
 * Guidance as of Feb 25, 2026
 */
int main() {
    const double tech_spend_b = 19.8; 
    const double nii_target_b = 104.5;
    const double expense_target_b = 105.0; // Non-interest expenses
    
    std::cout << "--- JPMORGAN CHASE 2026 STRATEGY ---" << std::endl;
    std::cout << "Tech Budget:     $" << tech_spend_b << "B (+10% YoY)" << std::endl;
    std::cout << "NII Projection:  $" << nii_target_b << "B" << std::endl;
    std::cout << "Expense Load:    $" << expense_target_b << "B" << std::endl;
    std::cout << "Status: Past 'Peak Modernization'; focus on Agentic AI Apps." << std::endl;
    return 0;
}
