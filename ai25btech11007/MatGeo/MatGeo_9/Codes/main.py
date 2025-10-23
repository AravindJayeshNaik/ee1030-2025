import numpy as np
import matplotlib.pyplot as plt

# Define lines
x = np.linspace(-10, 10, 400)

# Line 1: (8/3)x - 4y + 8 = 0  => y = -(8/3 * x + 8)/-4 = (8/12)x + 2
a, b = 8/3, -4
y1 = -(a*x + 8)/b

# Line 2: 2x - 3y = 0 => y = (2/3)x
y2 = (2/3)*x

# Plot
plt.figure(figsize=(7,7))
plt.axhline(0, color='black', linewidth=0.8)
plt.axvline(0, color='black', linewidth=0.8)

# Plot lines
plt.plot(x, y1, label='(8/3)x - 4y + 8 = 0', color='blue')
plt.plot(x, y2, label='2x - 3y = 0', color='red')

# Mark intercepts of line1
intercepts_line1 = [(-8/a,0), (0,-8/b)]
for point in intercepts_line1:
    plt.scatter(*point, color='blue')
    plt.text(point[0]+0.3, point[1]+0.3, f"{point}", color="blue")

# Mark intercepts of line2
intercepts_line2 = [(3,0),(0,-2)]
for point in intercepts_line2:
    plt.scatter(*point, color='red')
    plt.text(point[0]+0.3, point[1]+0.3, f"{point}", color="red")

plt.xlim(-6,6)
plt.ylim(-6,6)
plt.gca().set_aspect('equal', adjustable='box')
plt.legend()
plt.grid(True, linestyle="--", alpha=0.7)
plt.show()
