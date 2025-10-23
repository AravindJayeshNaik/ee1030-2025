import numpy as np

# Augmented matrix for the system
# lambda - 2*mu = 3
# 2*lambda - mu = 3
# -lambda - mu = 0
A = np.array([
    [1, -2, 3],
    [2, -1, 3],
    [-1, -1, 0]
], dtype=float)

# Number of unknowns
n = 2  # lambda and mu

# Perform Gaussian elimination manually
for i in range(n):
    # Make the diagonal element 1
    diag = A[i, i]
    A[i, i:] = A[i, i:] / diag
    
    # Eliminate the current variable from rows below
    for k in range(i+1, n):
        factor = A[k, i]
        A[k, i:] -= factor * A[i, i:]

# Back substitution
x = np.zeros(n)
for i in range(n-1, -1, -1):
    x[i] = A[i, n] - np.dot(A[i, i+1:n], x[i+1:n])

lambda_val = x[0]
mu_val = x[1]

print(f"lambda = {lambda_val}")
print(f"mu = {mu_val}")

# Intersection point
r = np.array([lambda_val*1, lambda_val*2, lambda_val*(-1)])
print(f"Intersection Point: {r}")
print("Shortest Distance = 0 units (lines intersect)")
