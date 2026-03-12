# Monte Carlo Option Pricing Engine (Quant Finance Project)

## Overview

This project implements a **Monte Carlo simulation engine** for pricing European call options using **Geometric Brownian Motion (GBM)** and compares the numerical results with the analytical **Black-Scholes model**.

The project demonstrates core quantitative finance concepts including stochastic simulation, numerical convergence, volatility sensitivity, and computational performance analysis.

## Objectives

The main goals of this project were:

* Implement stock price simulation using stochastic processes
* Price European options using Monte Carlo methods
* Validate numerical results against Black-Scholes formula
* Study convergence behaviour
* Analyze effect of volatility on pricing
* Measure runtime scalability
* Visualize convergence behaviour

## Mathematical Model

### Stock Price Model (Geometric Brownian Motion)

Stock evolution is modeled as:

[
S_T = S_0 e^{(r - \frac{1}{2}\sigma^2)T + \sigma\sqrt{T}Z}
]

Where:

* **S₀** → Initial stock price
* **r** → Risk-free interest rate
* **σ** → Volatility
* **T** → Time to maturity
* **Z** → Standard normal random variable

### Monte Carlo Pricing

European call option price estimated as:

[
C = e^{-rT} \frac{1}{N} \sum_{i=1}^{N} max(S_T^{(i)} - K,0)
]

Where:

* **N** = number of simulations
* Each simulation generates a possible future price

### Black-Scholes Formula

Used as analytical benchmark:

[
C = S_0 N(d_1) - K e^{-rT} N(d_2)
]

Where:

[
d_1 = \frac{\ln(S_0/K)+(r+\sigma^2/2)T}{\sigma\sqrt{T}}
]

[
d_2 = d_1 - \sigma\sqrt{T}
]

## Project Structure

```
Monte-Carlo-Option-Pricing/
│
├── src/
│    └── main.cpp
│
├── result/
│    └── convergence.csv
│
├── plots/
│    ├── convergence_sigma_0.1.png
│    ├── convergence_sigma_0.2.png
│    ├── convergence_sigma_0.3.png
│    └── convergence_sigma_0.4.png
│
├── plot/
│    └── plot.py
│
├── README.md
├── LICENSE
└── .gitignore
```

## Features Implemented

### Pricing Engine

* Monte Carlo option pricing
* Black-Scholes analytical pricing
* Error comparison

### Numerical Analysis

* Convergence testing
* Volatility sensitivity study
* Runtime benchmarking

### Engineering Features

* CSV data export
* Python visualization pipeline
* Performance timing using chrono
* Modular experimental design

## How to Run

### Compile C++ Simulation

From project root:

```
g++ src/main.cpp -o main
./main
```

This generates:

```
result/sample_output.csv
```

### Run Visualization Script

Install dependencies:

```
pip install pandas matplotlib
```

Run:

```
python plot/plot.py
```

This generates convergence plots inside:

```
plots/sample_convergence.png
```

## Convergence Results

Example convergence behaviour:

Monte Carlo estimates approach the Black-Scholes value as simulations increase.

| Simulations | Behaviour                  |
| ----------- | -------------------------- |
| 1k          | High noise                 |
| 10k         | Improving stability        |
| 100k        | Close to theoretical price |

## Convergence Visualization

Example convergence plot:

![Monte Carlo Convergence](plots/convergence_sigma_0.2.png)

## Experimental Insights

### Convergence Behaviour

Monte Carlo estimates converge toward the Black-Scholes price as simulations increase, validating the Law of Large Numbers.

### Volatility Impact

Higher volatility increases payoff variance, causing slower convergence. This demonstrates that Monte Carlo accuracy depends on payoff variance as well as simulation count.

### Runtime Scaling

Runtime increases approximately linearly with number of simulations, confirming expected O(N) complexity.

### Financial Insight

Higher volatility increases call option value because downside is limited (zero payoff) while upside remains unbounded.

### Key Quantitative Insight

Monte Carlo methods provide a universal pricing framework applicable even when closed-form solutions do not exist.

## Why Monte Carlo When Black-Scholes Exists?

Black-Scholes works for European options with simple payoffs. However, many real derivatives such as:

* Asian options
* Barrier options
* American options
* Path-dependent derivatives

do not have closed-form solutions.

Monte Carlo methods allow pricing of these complex derivatives by simulation, making them essential tools in quantitative finance.

## Technologies Used

### Programming

* C++
* Python

### Libraries

* STL random library
* Chrono performance library
* Pandas
* Matplotlib

### Concepts Demonstrated

* Stochastic processes
* Numerical simulation
* Statistical convergence
* Financial derivatives pricing
* Performance measurement
* Data visualization

## Possible Extensions

Future improvements could include:

* Variance reduction techniques
* American option pricing
* Greeks estimation
* Parallel Monte Carlo simulation
* Path-dependent option pricing
* Quasi-Monte Carlo methods

## Key Takeaways

This project strengthened understanding of:

• Monte Carlo simulation  
• Stochastic modelling  
• Numerical convergence  
• Financial derivatives pricing  
• Performance benchmarking  
• Research style experimentation  

## Author

**Nilesh Das**
BTech Computer Science
IIT Guwahati

## License

MIT License
