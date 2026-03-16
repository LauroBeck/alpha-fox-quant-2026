#include <iostream>
#include <format>

int main() {
    double current_brent = 104.15;
    double jpm_budget = 19'800'000'000.00;
    double variance = (current_brent - 100.00) * 0.025 * jpm_budget;

    std::cout << "\n--- C++20 FISCAL ENGINE: 2026 AUDIT ---\n";
    std::cout << std::format("BRENT CRUDE : ${:.2f}\n", current_brent);
    std::cout << std::format("JPM VARIANCE: ${:.2f} [CRITICAL]\n", variance);
    std::cout << "---------------------------------------\n";
    return 0;
}
