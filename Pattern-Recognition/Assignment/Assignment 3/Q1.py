# -*- coding: utf-8 -*-
"""PR_Assignment3_Q1.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1E4WG_mRleo_yiovR_-wH8ljOdU4BE91i

# **Q1. Consider the 128- dimensional feature vectors (d=128) given in the “gender_feature_vectors.csv” file. (2 classes, male and female)**
> **a) Use PCA to reduce the dimension from d to d’. (Here d=128)**

> **b) Select the appropriate dimension d’ (select d’ S.T first 95% of λ values)**

> **c) Use d’ features to classify the test cases (any classification algorithm taught in class like Bayes classifier, minimum distance classifier, and so on)**

> **Dataset Specifications:**

> > **Total number of samples = 800**

> > **Number of classes = 2 (labeled as “male” and “female”)**

> > **Samples from “1 to 400” belongs to class “male”**

> > **Samples from “401 to 800” belongs to class “female”**

> > **Number of samples per class = 400**

> > **Number of dimensions = 128**

> **Use the following information to design classifier:**

> > **Number of test cases ( first 10 in each class) = 20**

> > **Number of training feature vectors ( remaining 390 in each class) = 390**

> > **Number of reduced dimensions = d’ (map 128 to d’ features vector)**
"""

import numpy as np
import pandas as pd

"""
from google.colab import files
uploaded = files.upload()
"""

df = pd.read_csv('gender_feature_vectors.csv')

print("ACTUAL DATASET\n--------------")
print(df)
print('\n-------------------------------------------------------------------------------------------------------------------')

df.drop(df.columns[[0, 1]], axis = 1, inplace = True)

train_data_set = df.iloc[10:399]
train_data_set = train_data_set.append(df.iloc[409:801], ignore_index = True)

print("TRAIN DATASET WITH DIMENSION = 128\n----------------------------------")
print(train_data_set)
print('\n-------------------------------------------------------------------------------------------------------------------')

test_data_set = df.iloc[0:10]
test_data_set = test_data_set.append(df.iloc[399:409], ignore_index = True)

print("TEST DATASET WITH DIMENSION = 128\n---------------------------------")
print(test_data_set)
print('\n-------------------------------------------------------------------------------------------------------------------')

train_data_set = np.transpose(train_data_set)

test_data_set = np.transpose(test_data_set)

d = 128

print("DIMENSION OF FEATURE VECTORS\n----------------------------")
print("d = " + str(d))
print('\n-------------------------------------------------------------------------------------------------------------------')

def mean_PCA(train_data_set):
    train_data_set_mean = np.mean(train_data_set, axis = 1)
    return np.array(train_data_set_mean)

train_data_set_mean = mean_PCA(train_data_set)

print("MEAN OF TRAIN DATASET\n---------------------")
print(train_data_set_mean)
print('\n-------------------------------------------------------------------------------------------------------------------')

train_data_set_covariance_matrix = np.cov(train_data_set)

print("COVARIANCE MATRIX OF TRAIN DATASET\n----------------------------------")
print(train_data_set_covariance_matrix)
print('\n-------------------------------------------------------------------------------------------------------------------')

eigen_values, eigen_vectors = np.linalg.eigh(train_data_set_covariance_matrix)

eigen_pairs = [(np.abs(eigen_values[i]), eigen_vectors[:, i]) for i in range(len(eigen_values))]

eigen_pairs.sort(key = lambda x : x[0], reverse = True)

print("EIGEN VALUES IN INCREASING ORDER\n--------------------------------")
for i in eigen_pairs:
    print(i[0])
print('\n-------------------------------------------------------------------------------------------------------------------')

def get_reduced_dimension(eigen_pairs, eigen_values, percent):
    eigen_values_sum = np.sum(eigen_values)
    eigen_values_sum_reduced_dimension = percent * eigen_values_sum / 100
    sum = 0.0
    count = 0
    for i in eigen_pairs:
        if(sum < eigen_values_sum_reduced_dimension):
            sum += i[0]
            count += 1
        else:
            break
    return count

d_prime = get_reduced_dimension(eigen_pairs, eigen_values, 95)

print("REDUCED DIMENSION OF FEATURE VECTORS\n------------------------------------")
print("d' = " + str(d_prime))
print('\n-------------------------------------------------------------------------------------------------------------------')

matrix_w = eigen_pairs[0][1].reshape(d, 1)

for i in range(1, d_prime):
    matrix_w = np.hstack((matrix_w, eigen_pairs[i][1].reshape(d, 1)))

print("REDUCED DIMENSION MATRIX W\n--------------------------")
print(matrix_w)
print('\n-------------------------------------------------------------------------------------------------------------------')

train_data_set_transformed = np.transpose(matrix_w.T.dot(train_data_set))

print("TRAIN DATASET WITH DIMENSION = " + str(d_prime) + "\n---------------------------------")
print(train_data_set_transformed)
print('\n-------------------------------------------------------------------------------------------------------------------')

test_data_set_transformed = np.transpose(matrix_w.T.dot(test_data_set))

print("TEST DATASET WITH DIMENSION = " + str(d_prime) + "\n--------------------------------")
print(test_data_set_transformed)
print('\n-------------------------------------------------------------------------------------------------------------------')

"""# **Code for Plotting The Graphs**

Graph 1 : X-axis - No. of Dimension; Y-axis - Eigen Values

Graph 2 : X-axis - No. of Dimension; Y-axis - Variance
"""

import matplotlib.pyplot as plt

plot1 = plt.figure(1)
plt.scatter([i for i in range(d)], eigen_values, label = 'Eigen Values', color = 'blue')
plt.plot([i for i in range(d)], eigen_values, linestyle = '-', color = 'green')

plt.title('Eigen Value corresponding to each Dimension', fontweight = 'bold')
plt.xlabel('No. of Dimensions', fontweight = 'bold')
plt.ylabel('Eigen Values', fontweight = 'bold')

plt.axis([-1, d, -0.01, np.max(eigen_values) + 0.01])
plt.legend(loc = 'upper right')

plot2 = plt.figure(2)

x_values = []
y_values = []

x_values.append(0)
y_values.append(0.0)

sum = 0.0
total_sum = np.sum(eigen_values)

for i in range(d):
    sum += eigen_pairs[i][0]
    x_values.append(i + 1)
    y_values.append(sum / total_sum)

fp_num = np.linspace(0.0, 1.0, 1000)

plt.plot(x_values, y_values, color = 'blue')
plt.plot([i for i in range(d)], [0.95 for i in range(d)], linestyle = '-', label = '95' + str('%') + ' of Variance', color = 'red')
plt.plot([d_prime for i in range(len(fp_num))], fp_num, linestyle = '-', label = 'd\' = ' + str(d_prime), color = 'green')

plt.axis([0, d, 0.0, 1.05])

plt.title('Variance vs Dimension', fontweight = 'bold')
plt.xlabel('No. of Dimensions', fontweight = 'bold')
plt.ylabel('Variance', fontweight = 'bold')

plt.legend(loc = 'lower right')
plt.show()

"""# **Bayes Classifier Code**"""

from sklearn.naive_bayes import GaussianNB
from sklearn import metrics

"""# **Bayes Classifier with dimesion = 128**"""

train_data_set = np.transpose(train_data_set)
test_data_set = np.transpose(test_data_set)

X_train = train_data_set
y_train = []

variety = ['Male', 'Female']

for i in range(2):
    for j in range(int(len(train_data_set)/ 2)):
        y_train.append(variety[i])

X_test = test_data_set
y_test = []

for i in range(2):
    for j in range(int(len(test_data_set)/ 2)):
        y_test.append(variety[i])

gnb = GaussianNB()

gnb.fit(X_train, y_train)

y_pred = gnb.predict(X_test)

overall_accuracy = metrics.accuracy_score(y_test, y_pred) * 100

print("BAYES CLASSIFIER - DIMENSION = " + str(d) + "\n----------------------------------")
print("Actual Classification = Male")
print("Bayes Classifier : " + str(y_pred[0:10]))
print('')
print("Actual Classification = Female")
print("Bayes Classifier : " + str(y_pred[10:20]))
print('')

print("\nOverall Accuracy = " + str(overall_accuracy) + "%\n")
print('-------------------------------------------------------------------------------------------------------------------')

"""# **Bayes Classifier with dimesion = 57**"""

X_train_reduced_dimension = train_data_set_transformed
y_train_reduced_dimension = []

variety = ['Male', 'Female']

for i in range(2):
    for j in range(int(len(train_data_set_transformed)/ 2)):
        y_train_reduced_dimension.append(variety[i])

X_test_reduced_dimension = test_data_set_transformed
y_test_reduced_dimension = []

for i in range(2):
    for j in range(int(len(test_data_set_transformed)/ 2)):
        y_test_reduced_dimension.append(variety[i])

gnb_reduced_dimension = GaussianNB()

gnb_reduced_dimension.fit(X_train_reduced_dimension, y_train_reduced_dimension)

y_pred_reduced_dimension = gnb_reduced_dimension.predict(X_test_reduced_dimension)

overall_accuracy_reduced_dimension = metrics.accuracy_score(y_test_reduced_dimension, y_pred_reduced_dimension) * 100

print("BAYES CLASSIFIER - DIMENSION = " + str(d_prime) + "\n----------------------------------")
print("Actual Classification = Male")
print("Bayes Classifier : " + str(y_pred_reduced_dimension[0:10]))
print('')
print("Actual Classification = Female")
print("Bayes Classifier : " + str(y_pred_reduced_dimension[10:20]))
print('')

print("\nOverall Accuracy = " + str(overall_accuracy_reduced_dimension) + "%\n")
print('-------------------------------------------------------------------------------------------------------------------')

"""# **Confusion Matrix**"""

matrix = metrics.plot_confusion_matrix(gnb_reduced_dimension, X_test_reduced_dimension, y_test_reduced_dimension, cmap = plt.cm.Blues)

plt.title('Confusion Matrix')
plt.show()