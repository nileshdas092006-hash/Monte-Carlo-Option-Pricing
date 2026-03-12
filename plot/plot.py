import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("../result/convergence.csv")
# print(data.columns)
# for sigma in data["Sigmas"].unique():
#     subset = data[data["Sigmas"] == sigma]

#     plt.plot(subset["Simulations"],
#              subset["MC_Price"],
#              marker="o",
#              label=f"MC sigma={sigma}")

#     plt.axhline(subset["BS_Price"].iloc[0],
#             linestyle="dashed",
#             label=f"BS sigma={sigma}")

# plt.xlabel("Simulations")
# plt.ylabel("Option Price")
# plt.title("Monte Carlo Convergence")
# plt.legend()
# plt.show()
for sigma in data["Sigmas"].unique():

    subset = data[data["Sigmas"] == sigma]

    plt.figure()

    plt.plot(subset["Simulations"],
             subset["MC_Price"],
             marker="o",
             label="Monte Carlo")

    plt.axhline(subset["BS_Price"].iloc[0],
                linestyle="dashed",
                label="Black-Scholes")

    plt.xlabel("Simulations")
    plt.ylabel("Option Price")
    plt.title(f"Convergence (sigma={sigma})")

    plt.legend()
    plt.grid(True)
    plt.savefig(f"../plots/convergence_sigma_{sigma}.png")
    plt.close()