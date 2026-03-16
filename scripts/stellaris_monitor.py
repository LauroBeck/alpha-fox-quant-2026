import random
import time

def get_node_telemetry():
    """
    Simulates real-time telemetry from the Stargate Cluster nodes.
    Target: 1.85GHz Sovereign Clock-Gate
    """
    nodes = [f"STELLARIS-NODE-{i:03}" for i in range(1, 6)]
    report = []
    
    for node in nodes:
        # Standard temp: 45-55C at 1.85GHz | Fail: >75C
        temp = random.uniform(48.2, 52.7)
        clock = 1.85 # Fixed by Sovereign Tier logic
        load = random.uniform(88.0, 94.5)
        report.append({"id": node, "temp": temp, "clock": clock, "load": load})
    return report

def audit_cluster():
    print(f"🏛️ ARCHITECT: Lauro Beck | TELEMETRY: Stellaris Cluster")
    print(f"SESSION: March 16, 2026 | TARGET CLOCK: 1.85GHz")
    print(f"----------------------------------------------------------")
    print(f"{'NODE ID':<18} | {'TEMP':<7} | {'CLOCK':<7} | {'LOAD'}")
    
    telemetry = get_node_telemetry()
    safe = True
    
    for data in telemetry:
        status = "OK" if data['temp'] < 60 else "WARN"
        if status == "WARN": safe = False
        
        print(f"{data['id']:<18} | {data['temp']:.1f}°C | {data['clock']}GHz | {data['load']:.1f}% [{status}]")

    print(f"----------------------------------------------------------")
    if safe:
        print("SYSTEM STATUS: 🟢 SOVEREIGN GATING ACTIVE & STABLE")
    else:
        print("SYSTEM STATUS: 🟡 THERMAL DRIFT DETECTED")

if __name__ == "__main__":
    audit_cluster()
