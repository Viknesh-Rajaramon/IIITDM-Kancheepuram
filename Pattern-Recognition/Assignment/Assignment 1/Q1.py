import numpy as np
import matplotlib.pyplot as plt
import math

# to calculate KL distance
def kl_distance(p,q):
    return sum(p[i] * np.log2(p[i]/q[i]) for i in range(len(p)))

# calculate Bhattacharya distance - for normalized histograms
def bhattacharya_distance(p,q):
    # mean of p and q
    p_mean = np.average(p)
    q_mean = np.average(q)
    
    dist = 0
    for i in range(len(p)):
        dist += math.sqrt(p[i]*q[i])
        
    dist = math.sqrt(1-dist)
    
    return dist 

# Store normalized histograms H1 and H2 in numpy arrays
h1 = [0.24, 0.2, 0.16, 0.12, 0.08, 0.04, 0.12, 0.04]
H1 = np.array(h1)
h2 = [0.22, 0.23, 0.16, 0.13, 0.11, 0.08, 0.05, 0.02]
H2 = np.array(h2)

# KL (H1 || H2)
kl_h1_h2 = kl_distance(H1,H2)
print('KL(H1 || H2): %.3f ' % kl_h1_h2)

# KL (H2 || H1)
kl_h2_h1 = kl_distance(H2,H1)
print('KL(H2 || H1): %.3f ' % kl_h2_h1)
    
# Bhattacharya (H1 || H2)
b_h1_h2 = bhattacharya_distance(H1,H2)
print('Bhattacharya (H1 and H2): %.3f ' % b_h1_h2)

# Bhattacharya (H2 || H1)
b_h2_h1 = kl_distance(H2,H1)
print('Bhattacharya (H2 and H1): %.3f ' % b_h2_h1)

# Plot the normalized histograms for visualization
x = [1,2,3,4,5,6,7,8]
plt.subplot(2,1,1)
plt.bar(x,H1)
plt.subplot(2,1,2)
plt.bar(x,H2)