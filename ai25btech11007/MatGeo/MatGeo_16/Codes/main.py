import numpy as np
import matplotlib.pyplot as plt

# Define x range for the parabola (both branches)
x = np.linspace(0, 10, 400)
y_upper = 3 * np.sqrt(x)
y_lower = -3 * np.sqrt(x)

# Line y = 3x
x_line = np.linspace(0, 2, 200)
y_line = 3 * x_line

# Plot setup
plt.figure(figsize=(7,6))
plt.plot(x, y_upper, 'b', label=r'$y = 3\sqrt{x}$')
plt.plot(x, y_lower, 'b', linestyle='--', label=r'$y = -3\sqrt{x}$')
plt.plot(x_line, y_line, 'r', label=r'$y = 3x$')

# Fill the bounded area
x_fill = np.linspace(0, 1, 200)
plt.fill_between(x_fill, 3*x_fill, 3*np.sqrt(x_fill), color='lightblue', alpha=0.5)

# Mark intersection points
plt.scatter([0,1], [0,3], color='black')
plt.text(0, -0.5, 'A(0,0)', ha='center', fontsize=10)
plt.text(1, 3.3, 'B(1,3)', ha='center', fontsize=10)

# Axes and labels
plt.axhline(0, color='k', linewidth=1)
plt.axvline(0, color='k', linewidth=1)
plt.title(r'Region bounded by $y^2 = 9x$ and $y = 3x$', fontsize=13)
plt.xlabel(r'$x$')
plt.ylabel(r'$y$')
plt.legend(loc='upper right')
plt.grid(True, linestyle='--', alpha=0.6)
plt.axis('equal')
plt.xlim(-1, 10)
plt.ylim(-10, 10)
plt.show()
