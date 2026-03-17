import numpy as np
import json
import os
from qiskit.circuit.library import n_local
from qiskit.primitives import StatevectorSampler
from qiskit_finance.applications.optimization import PortfolioOptimization
from qiskit_optimization.algorithms import MinimumEigenOptimizer
from qiskit_algorithms import SamplingVQE
from qiskit_algorithms.optimizers import COBYLA

def run_sovereign_quantum_audit():
    print("--- 2026 Quantum Sovereign Alpha Engine (V7.2 Stargate-Linked) ---")
    market_file = 'market_snapshot.json'
    
    # Baseline expected returns
    mu = np.array([0.05, 0.08, 0.12, 0.04, 0.07, 0.06])
    risk_factor = 0.2

    if os.path.exists(market_file):
        with open(market_file, 'r') as f:
            data = json.load(f)
            # Support for the Stargate nested structure
            if isinstance(data, dict) and 'market' in data:
                print(f"Stargate Pulse Detected: Theta {data.get('quantum_theta', 0):.4f}")
                sentiment = data['market'].get('brent_sentiment', 0)
                # Adjust returns based on B-PIPE geopolitical sentiment
                mu = mu * (1 + sentiment * 0.1)
                vix = data['market'].get('vix_volatility', 20)
                risk_factor = 0.25 if vix > 23 else 0.15
                print(f"Market Context: VIX {vix}")
            else:
                # Fallback for legacy list structures
                try:
                    mu = np.array([item['Price']/1000 for item in data][:6])
                except (TypeError, KeyError):
                    print("Warning: Market snapshot format unrecognized. Using baseline mu.")

    num_assets = len(mu)
    seed = 123
    sigma = np.random.default_rng(seed).standard_normal((num_assets, num_assets))
    sigma = (sigma.T @ sigma) / 1000 
    
    portfolio = PortfolioOptimization(expected_returns=mu, covariances=sigma, risk_factor=risk_factor, budget=3)
    qp = portfolio.to_quadratic_program()
    
    sampler = StatevectorSampler()
    ansatz = n_local(num_assets, rotation_blocks='ry', entanglement_blocks='cz', reps=2, entanglement='full')
    
    sampling_vqe = SamplingVQE(sampler=sampler, ansatz=ansatz, optimizer=COBYLA())
    optimizer = MinimumEigenOptimizer(sampling_vqe)
    
    result = optimizer.solve(qp)
    
    print("\n--- Quantum Audit Results ---")
    print(f"Optimal Asset Selection: {result.x}")
    print(f"Projected Quantum Alpha: {result.fval:.4f}")

if __name__ == "__main__":
    run_sovereign_quantum_audit()
