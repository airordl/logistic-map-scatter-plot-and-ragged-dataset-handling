import matplotlib.pyplot as plt
import numpy as np


plt.figure(figsize=(10, 6))

max_r_index = 0

with open("logi.dat") as f:
    for i, line in enumerate(f):
        if not line.strip():
            continue
        try:
            y_vals = list(map(float, line.strip().split()))
        except ValueError:
            continue
        
        x_vals = np.linspace(0, 1, len(y_vals))  # or j/max_len if needed
        plt.scatter(x_vals, y_vals,marker = '.', s=10, alpha = 0.5)
        max_r_index = max(max_r_index, len(y_vals))

plt.title('Logistic Map (Fast Scatter)')
plt.xlabel('Index (normalized)')
plt.ylabel('x value')
plt.ylim(0, 1)
plt.grid(True)
plt.tight_layout()
plt.show()

