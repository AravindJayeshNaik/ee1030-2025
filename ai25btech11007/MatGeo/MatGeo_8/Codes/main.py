import math

# Plane: 3x + 5y + 4z = 11
n = [3, 5, 4]  # Normal vector
d_plane = 11   # Plane constant
distance = 2 * math.sqrt(2)  # Given distance

# Point: (2, 1, lambda)
x, y = 2, 1

# Norm of the normal vector
norm_n = math.sqrt(n[0]**2 + n[1]**2 + n[2]**2)  # ||n||

# Solve for lambda using distance formula:
# |n . p - d_plane| / ||n|| = distance
# n . p = 3*2 + 5*1 + 4*lambda = 11 + 4*lambda
# |11 + 4*lambda - 11| / (5*sqrt(2)) = 2*sqrt(2)
# => |4*lambda| / (5*sqrt(2)) = 2*sqrt(2)
# => |lambda| = 5

lambda_val = 5
print(f"Lambda = {lambda_val} or {-lambda_val}")
