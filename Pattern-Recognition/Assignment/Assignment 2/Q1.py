# -*- coding: utf-8 -*-
"""Q1.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1EyJf_5qoFYYEghYJF90ScsvGYH4PcSU7

# **Q1. Find and plot the decision boundary between class ω1 and ω2. Assume P(ω1) = P(ω2).**
# **ω1 = [1,6; 3,4; 3,8; 5,6]**
# **ω2 = [3,0; 1,-2;3,-4;5,-2]**
"""

class_1 = [[1, 6], [3, 4], [3, 8], [5, 6]]
class_2 = [[3, 0], [1, -2], [3, -4], [5, -2]]

# Probability of Class 1 and Class 2
class_1_probability = 1/2
class_2_probability = 1/2

print('-----------------------------------------------------------------------------------------')
print("PROBABILITY - P(\u03C9)\n-------------------")
print("Class \u03C9\u2081 = " + str(class_1_probability))
print("Class \u03C9\u2082 = " + str(class_2_probability))
print('')
print('-----------------------------------------------------------------------------------------')

import pandas as pd
import numpy as np

class_1 = pd.DataFrame(data = class_1, columns = ['x', 'y'])
class_2 = pd.DataFrame(data = class_2, columns = ['x', 'y'])

class_1_mean = np.array(np.mean(class_1))
class_2_mean = np.array(np.mean(class_2))

print("MEAN - \u03BC\n--------")
print("Class \u03C9\u2081 = " + str(class_1_mean))
print("Class \u03C9\u2082 = " + str(class_2_mean))
print('')
print('-----------------------------------------------------------------------------------------')

class_1_covariance_matrix = np.array(class_1.cov())
class_2_covariance_matrix = np.array(class_2.cov())

print("COVARIANCE - \u03A3\n--------------")
print("Class \u03C9\u2081 :\n" + str(class_1_covariance_matrix))
print('')
print("Class \u03C9\u2082 :\n" + str(class_2_covariance_matrix))
print('')
print('-----------------------------------------------------------------------------------------')

from sympy import Matrix, solve, symbols, simplify

x, y = symbols('x y')

X = Matrix([x, y])

X

# Function to get the expression for gi(X)
def get_gi_X(X, mean, covariance_matrix, probability):
    temp_1 = np.subtract(X, mean)
    temp_2 = (-1/2) * (np.transpose(temp_1)) @ (np.linalg.inv(covariance_matrix)) @ (temp_1)
    temp_3 = (-1/2) * (np.log(np.linalg.det(covariance_matrix)))
    temp_4 = np.log(probability)
    return simplify(temp_2 + temp_3 + temp_4)

g1_X = get_gi_X(X, class_1_mean.reshape(2,1), class_1_covariance_matrix, class_1_probability)
g2_X = get_gi_X(X, class_2_mean.reshape(2,1), class_2_covariance_matrix, class_2_probability)

print("DISCRIMINANT FUNCTIONS\n----------------------")
print("g\u2081(X) = " + str(g1_X[0][0]))
print('')
print("g\u2082(X) = " + str(g2_X[0][0]))
print('')
print('-----------------------------------------------------------------------------------------')

def get_g_X(g1_X, g2_X):
    return simplify(np.subtract(g1_X, g2_X))

g_X = get_g_X(g1_X[0][0], g2_X[0][0])

print("\ng(X) = " + str(g_X))
print('-----------------------------------------------------------------------------------------')

decision_boundary_solution = solve(g_X, (x, y))

print("\nSolution to the Equation g(X) = " + str(decision_boundary_solution[0]) + "\n")

import matplotlib.pyplot as plt

"""Code for plotting the points and the decision boundary"""

# Generatinging points for drawing the decision boundary
x_values = np.linspace(-2, 6, 1000)

# Data points of Class 1 and Class 2
plt.scatter(x = class_1['x'], y = class_1['y'], label = "Class $\u03C9_{1}$", color = 'blue')
plt.scatter(x = class_2['x'], y = class_2['y'], label = "Class $\u03C9_{2}$", color = 'cyan')

# Mean of Class 1 and Class 2
plt.scatter(x = class_1_mean[0], y = class_1_mean[1], label = "Mean - Class $\u03C9_{1}$", color = 'yellow')
plt.scatter(x = class_2_mean[0], y = class_2_mean[1], label = "Mean - Class $\u03C9_{2}$", color = 'purple')

# Plotting the Decision Boundary
plt.plot(x_values, [decision_boundary_solution[0][1] for i in x_values], linestyle = '-', color = 'green', label = 'Decision Boundary')

# Plotting a Line between Mean of Class 1 and Class 2
plt.plot([class_1_mean[0], class_2_mean[0]], [class_1_mean[1], class_2_mean[1]], linestyle = '-', color = 'red', label = 'Joining Mean Points')

plt.legend(loc = 'upper left')
plt.show()