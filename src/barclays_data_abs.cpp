#include <iostream>
#include <iomanip>

/**
 * Barclays: Data Center ABS Financing
 * Deal: Yondr Group £532M (Mar 5, 2026)
 */
int main() {
    const double deal_size_m = 532.0; // £532M
    const double usd_equiv_m = 680.9;
    
    std::cout << "--- BARCLAYS DATA CENTER FINANCING ---" << std::endl;
    std::cout << "Deal: Yondr Group ABS (Asset-Backed Security)" << std::endl;
    std::cout << "Size: £" << deal_size_m << "M ($" << std::fixed << std::setprecision(1) << usd_equiv_m << "M)" << std::endl;
    std::cout << "Role: Sole Green Structuring Advisor" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "ANALYSIS: Shift toward 'Securitized AI Infrastructure' has begun." << std::endl;
    return 0;
}
