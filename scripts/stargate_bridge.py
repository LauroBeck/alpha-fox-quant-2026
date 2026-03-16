import subprocess
import os

def call_efficiency_core(daily_tax_m=45000.0):
    """
    Architect's Bridge: Passes Python-calculated tax loads 
    into the high-performance C++ Efficiency Core.
    """
    binary_path = "./bin/efficiency_optimizer"
    
    if not os.path.exists(binary_path):
        print(f"🏛️ ARCHITECT: Lauro Beck | STATUS: Error - C++ Binary not found.")
        print(">> TIP: Compile with: g++ -O3 -std=c++20 src/efficiency_optimizer.cpp -o bin/efficiency_optimizer")
        return

    print(f"🏛️ ARCHITECT: Lauro Beck | ACTION: Triggering C++ Core Simulation...")
    print(f"STRESS LOAD: ${daily_tax_m:,.2f}M Daily Energy Drag")
    print(f"----------------------------------------------------------")
    
    try:
        result = subprocess.run([binary_path], capture_output=True, text=True, check=True)
        print(result.stdout)
    except subprocess.CalledProcessError as e:
        print(f"CRITICAL: C++ Core Execution Failed: {e}")

if __name__ == "__main__":
    # Current load calibrated to today's $104.22 Brent resistance point
    call_efficiency_core(daily_tax_m=45000.0)
