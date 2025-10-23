import numpy as np
import matplotlib.pyplot as plt

# Parabola equation from matrix form:
# 4x² + 4xy + y² + 4x - 8y + 16 = 0
# We'll use this to plot the curve.

# Define grid
x = np.linspace(-8, 6, 400)
y = np.linspace(-4, 8, 400)
X, Y = np.meshgrid(x, y)

# Define the equation of the parabola
F = 4*X**2 + 4*X*Y + Y**2 + 4*X - 8*Y + 16

# Plot the parabola (F=0)
plt.contour(X, Y, F, levels=[0], colors='b', linewidths=2, label='Parabola')

# Plot directrix: x - 2y + 3 = 0  →  y = (x + 3)/2
x_dir = np.linspace(-8, 6, 200)
y_dir = (x_dir + 3) / 2
plt.plot(x_dir, y_dir, 'g--', label='Directrix')

# Focus point (-1, 2)
plt.plot(-1, 2, 'ro', label='Focus (-1, 2)')

# Graph settings
plt.axis('equal')
plt.grid(True, linestyle='--', alpha=0.6)
plt.title('Parabola with Focus (-1, 2) and Directrix x - 2y + 3 = 0')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.legend()
plt.show()
