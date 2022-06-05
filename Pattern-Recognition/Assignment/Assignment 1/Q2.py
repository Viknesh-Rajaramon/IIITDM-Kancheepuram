import numpy as np

arr_transpose = np.array([[0.5, 0.5, -0.5, -0.25, -0.25]]) # Stores (hq-ht)ᵀ
arr = arr_transpose.transpose() # Calculates (hq-ht) from (hq-ht)ᵀ

# Stores array A
A = np.array([[1, 0.135, 0.195, 0.137, 0.157], [0.135, 1, 0.2, 0.309, 0.143], [0.195, 0.2, 1, 0.157, 0.122], [0.137, 0.309, 0.157, 1, 0.195], [0.157, 0.143, 0.122, 0.195, 1]])

B = A.dot(arr) # Calculates A (hq-ht)
C = arr_transpose.dot(B) # Calculates (hq-ht)ᵀ A (hq-ht)

print("\n\tQUADRATIC FORM DISTANCE = " + str(round(C[0][0],10)) + "\n")