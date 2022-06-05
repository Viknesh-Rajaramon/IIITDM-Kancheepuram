import numpy as np
import pandas as pd
from urllib.request import urlretrieve
import cv2
import matplotlib.pyplot as plt

df = pd.read_csv('Iris_dataset.csv')

df = df.drop(['sepal.length', 'sepal.width'], axis=1)
test = df.iloc[[0, 50, 100]]
train_data_set = df.drop(df.index[[0, 50, 100]])

C1 = train_data_set.loc[train_data_set.variety == 'Setosa']
C2 = train_data_set.loc[train_data_set.variety == 'Versicolor']
C3 = train_data_set.loc[train_data_set.variety == 'Virginica']

lm1 = np.mean(C1['petal.length'])
lm2 = np.mean(C2['petal.length'])
lm3 = np.mean(C3['petal.length'])
wm1 = np.mean(C1['petal.width'])
wm2 = np.mean(C2['petal.width'])
wm3 = np.mean(C3['petal.width'])

c1 = C1.drop(['variety'], axis = 1)
c2 = C2.drop(['variety'], axis = 1)
c3 = C3.drop(['variety'], axis = 1)

cov_1 = np.linalg.inv(np.cov(c1.T))
cov_2 = np.linalg.inv(np.cov(c2.T))
cov_3 = np.linalg.inv(np.cov(c3.T))

categ = ['Setosa', 'Versicolor', 'Virginica']

print('')
print(test)
print('')

for i in range(len(test)):
	print("\n\nTest Data " + str(i+1)+ " : Actual Class = " + categ[i] + "\n")
	l = np.float64(test.iloc[[i]]['petal.length'])
	w = np.float64(test.iloc[[i]]['petal.width'])
	right_mat1 = np.array([lm1 - l, wm1 - w])
	left_mat1 = right_mat1.T
	e1 = np.dot(np.dot(left_mat1, cov_1), right_mat1)
	print('Mahalanobis distance with class Setosa     = ',e1)
	right_mat2 = np.array([lm2 - l, wm2 - w])
	left_mat2 = right_mat2.T
	e2 = np.dot(np.dot(left_mat2, cov_2), right_mat2)
	print('Mahalanobis distance with class Versicolor = ',e2)
    
	right_mat3 = np.array([lm3 - l, wm3 - w])
	left_mat3 = right_mat3.T
	e3 = np.dot(np.dot(left_mat3, cov_3), right_mat3)
	print('Mahalanobis distance with class Virginica  = ',e3)
	print('\n\tPredicted Class = ', categ[np.argmin(np.array([e1, e2, e3]))])

print('')

# Code for the Scatter plot - Contains Data points, Mean points and Test case points of all the flower varieties
plt.plot(C1['petal.length'], C1['petal.width'], marker = "o", linestyle = "", label = categ[0], color = 'blue')
plt.plot(C2['petal.length'], C2['petal.width'], marker = "o", linestyle = "", label = categ[1], color = 'orange')
plt.plot(C3['petal.length'], C3['petal.width'], marker = "o", linestyle = "", label = categ[2], color = 'green')

plt.plot(np.float64(test.iloc[[0]]['petal.length']), np.float64(test.iloc[[0]]['petal.width']), marker="s", linestyle="", label="Test case 1 - " + categ[0] + " (Flower 0)", color = 'red')
plt.plot(np.float64(test.iloc[[1]]['petal.length']), np.float64(test.iloc[[1]]['petal.width']), marker="s", linestyle="", label="Test case 2 - " + categ[1] + " (Flower 50)", color = 'black')
plt.plot(np.float64(test.iloc[[2]]['petal.length']), np.float64(test.iloc[[2]]['petal.width']), marker="s", linestyle="", label="Test case 3 - " + categ[2] + " (Flower 100)", color = 'yellow')

plt.plot(lm1, wm1, marker = "D", linestyle = "", label = "Mean - " + categ[0], color = 'olive')
plt.plot(lm2, wm2, marker = "D", linestyle = "", label = "Mean - " + categ[1], color = 'purple')
plt.plot(lm3, wm3, marker = "D", linestyle = "", label = "Mean - " + categ[2], color = 'cyan')

# Plotting the line between Mean and Test case data
plt.plot([lm1, np.float64(test.iloc[[0]]['petal.length'])], [wm1, np.float64(test.iloc[[0]]['petal.width'])], color = 'black')
plt.plot([lm2, np.float64(test.iloc[[1]]['petal.length'])], [wm2, np.float64(test.iloc[[1]]['petal.width'])], color = 'black')
plt.plot([lm3, np.float64(test.iloc[[2]]['petal.length'])], [wm3, np.float64(test.iloc[[2]]['petal.width'])], color = 'black')

plt.legend()
plt.suptitle("Iris Dataset Classification", fontweight = "bold")
plt.xlabel("Petal length (in cm)", fontweight = "bold")
plt.ylabel("Petal width (in cm)", fontweight = "bold")
plt.show()