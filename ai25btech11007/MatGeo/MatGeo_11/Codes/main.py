import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Define k (nonzero)
k = 2

# Planes equations: coefficients and RHS
planes = [
    (np.array([1, 1, 1]), 2),    # x + y + z = 2
    (np.array([2, 1, -1]), 3),   # 2x + y - z = 3
    (np.array([3, 2, k]), 4)     # 3x + 2y + k z = 4
]

# Solve for intersection point
A = np.array([p[0] for p in planes])
b = np.array([p[1] for p in planes])
solution = np.linalg.solve(A, b)

# Create grid for plotting planes
xx, yy = np.meshgrid(np.linspace(-2, 3, 50), np.linspace(-2, 3, 50))

# Calculate corresponding z for each plane
zz1 = (2 - xx - yy)
zz2 = (3 - 2*xx - yy) * -1
zz3 = (4 - 3*xx - 2*yy) / k

# Plot planes and intersection point
fig = plt.figure(figsize=(8, 6))
ax = fig.add_subplot(111, projection='3d')

ax.plot_surface(xx, yy, zz1, alpha=0.5, color='red')
ax.plot_surface(xx, yy, zz2, alpha=0.5, color='green')
ax.plot_surface(xx, yy, zz3, alpha=0.5, color='blue')

# Plot solution point
ax.scatter(*solution, color='black', s=50, label=f"Solution {solution.round(2)}")

ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.legend()
ax.set_title(f"Intersection of 3 Planes (k={k})")

plt.show()
