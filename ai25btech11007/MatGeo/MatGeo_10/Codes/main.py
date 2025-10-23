import numpy as np

def check_coplanarity(alpha):
    # Direction vectors
    v1 = np.array([5, 3 - alpha, -2])
    v2 = np.array([alpha, -1, 2 - alpha])

    # Form matrix with direction vectors as columns
    M = np.column_stack((v1, v2))

    # Rank of coefficient matrix
    rank = np.linalg.matrix_rank(M)

    # Since both lines pass through origin, always coplanar
    return rank <= 2
# Test for some sample alpha values
alpha_values = [-3, -1, 0, 1, 2, 3, 5]
for a in alpha_values:
    result = check_coplanarity(a)
    print(f"alpha = {a:2d} -> Coplanar: {result}")

print("\nConclusion: Lines are coplanar for all real alpha.")