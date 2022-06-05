# -*- coding: utf-8 -*-
"""Q4.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1-ih05TpTqKbDiNVvoPo1whnq4gJkfEhj

# **Q4. Implement Bayes Classifier for Iris Dataset.**
> **Dataset Specifications:**
> > **Total number of samples = 150**

> > **Number of classes = 3 (Iris setosa, Iris virginica, and Iris versicolor)**

> > **Number of samples in each class = 50**

> **Use the following information to design classifier:**
> > **Number of training feature vectors ( first 40 in each class) = 40**

> > **Number of test feature vectors ( remaining 10 in each class) = 10**

> > **Number of dimensions = 4**

> > **Feature vector = <sepal length, sepal width, petal length, petal width>**
# **If the samples follow a multivariate normal density, find the accuracy of classification for the test feature vectors.**
"""

import pandas as pd
import numpy as np

df = pd.read_csv('Iris_dataset.csv')

train_data_set1 = df.iloc[0:40]
test_data_set1 = df.iloc[40:50]

train_data_set2 = df.iloc[50:90]
test_data_set2 = df.iloc[90:100]

train_data_set3 = df.iloc[100:140]
test_data_set3 = df.iloc[140:150]

d = 4

print("Dimension of Feature Vectors = " + str(d))

class_1_probability = 1/3
class_2_probability = 1/3
class_3_probability = 1/3

print('---------------------------------------------------------------------------------------------------------------------------------------------------------------')
print("PROBABILITY - P(\u03C9)\n------------------")
print("Class \u03C9\u2081 = " + str(class_1_probability))
print("Class \u03C9\u2082 = " + str(class_2_probability))
print("Class \u03C9\u2083 = " + str(class_3_probability))
print('')
print('---------------------------------------------------------------------------------------------------------------------------------------------------------------')

def find_mean(data):
    data_mean = np.array([np.mean(data['sepal.length']), np.mean(data['sepal.width']), np.mean(data['petal.length']), np.mean(data['petal.width'])])
    return data_mean

class_1_mean = find_mean(train_data_set1)
class_2_mean = find_mean(train_data_set2)
class_3_mean = find_mean(train_data_set3)

print("MEAN - \u03BC\n--------")
print("Class \u03C9\u2081 = " + str(class_1_mean))
print("Class \u03C9\u2082 = " + str(class_2_mean))
print("Class \u03C9\u2083 = " + str(class_3_mean))
print('')
print('---------------------------------------------------------------------------------------------------------------------------------------------------------------')

class_1_covariance_matrix = train_data_set1.cov()
class_2_covariance_matrix = train_data_set2.cov()
class_3_covariance_matrix = train_data_set3.cov()

print("COVARIANCE - \u03A3\n--------------")
print("Class \u03C9\u2081 :\n" + str(class_1_covariance_matrix.values))
print('')
print("Class \u03C9\u2082 :\n" + str(class_2_covariance_matrix.values))
print('')
print("Class \u03C9\u2083 :\n" + str(class_3_covariance_matrix.values))
print('')
print('---------------------------------------------------------------------------------------------------------------------------------------------------------------')

# Function to find P(X/w) for Multivariant case
def class_conditional_probability(X, d, mean, covariance_matrix):
    temp_1 = np.subtract(X, mean)
    temp_2 = (-1/2) * (np.transpose(temp_1)) @ (np.linalg.inv(covariance_matrix)) @ (temp_1)
    temp_3 = (2*np.pi)**(d/2)
    temp_4 = (np.linalg.det(covariance_matrix))**(1/2)
    temp_5 = temp_3 * temp_4
    return (np.exp(temp_2)/temp_5)

# Function to classify the test data into one of the classes
def get_variety_for_test_data(test_data, class_1_mean, class_2_mean, class_3_mean, class_1_covariance_matrix, class_2_covariance_matrix, class_3_covariance_matrix):
    temp = test_data.drop(['variety'], axis = 1)
    variety = ['Setosa', 'Versicolor', 'Virginica']
    test_data_variety = []

    for X in temp[:].values:
        p_x_class_1 = class_conditional_probability(X, d, class_1_mean, class_1_covariance_matrix)
        p_x_class_2 = class_conditional_probability(X, d, class_2_mean, class_2_covariance_matrix)
        p_x_class_3 = class_conditional_probability(X, d, class_3_mean, class_3_covariance_matrix)
        
        maximum_probability = max(p_x_class_1, p_x_class_2, p_x_class_3)

        if(maximum_probability == p_x_class_1):
            test_data_variety.append(variety[0])
        elif(maximum_probability == p_x_class_2):
            test_data_variety.append(variety[1])
        else:
            test_data_variety.append(variety[2])
    return test_data_variety

test_data_set1_variety = get_variety_for_test_data(test_data_set1, class_1_mean, class_2_mean, class_3_mean, class_1_covariance_matrix, class_2_covariance_matrix, class_3_covariance_matrix)
test_data_set2_variety = get_variety_for_test_data(test_data_set2, class_1_mean, class_2_mean, class_3_mean, class_1_covariance_matrix, class_2_covariance_matrix, class_3_covariance_matrix)
test_data_set3_variety = get_variety_for_test_data(test_data_set3, class_1_mean, class_2_mean, class_3_mean, class_1_covariance_matrix, class_2_covariance_matrix, class_3_covariance_matrix)

print("CLASSIFICATION AS PER BAYES CLASSIFIER AND ACTUAL CLASSIFICATION\n----------------------------------------------------------------")
print("Actual Classification = Setosa")
print("Bayes Classifier : " + str(test_data_set1_variety))
print('')
print("Actual Classification = Versicolor")
print("Bayes Classifier : " + str(test_data_set2_variety))
print('')
print("Actual Classification = Virginica")
print("Bayes Classifier : " + str(test_data_set3_variety))
print('')
print('---------------------------------------------------------------------------------------------------------------------------------------------------------------')

# Function to get accuracy for separate classes
def get_accuracy_class(bayes_classifier, actual_classification):
    count = 0
    for classification in bayes_classifier:
        if(classification == actual_classification):
            count += 1
    return count

test_data_set1_accuracy = (get_accuracy_class(test_data_set1_variety, 'Setosa')/len(test_data_set1))
test_data_set2_accuracy = (get_accuracy_class(test_data_set2_variety, 'Versicolor')/len(test_data_set2))
test_data_set3_accuracy = (get_accuracy_class(test_data_set3_variety, 'Virginica')/len(test_data_set3))

print("ACCURACY OF MODEL\n-----------------")
print("Class \u03C9\u2081 = " + str("{:.00%}".format(test_data_set1_accuracy)))
print('')
print("Class \u03C9\u2082 = " + str("{:.00%}".format(test_data_set2_accuracy)))
print('')
print("Class \u03C9\u2083 = " + str("{:.00%}".format(test_data_set3_accuracy)))
print('')
print('---------------------------------------------------------------------------------------------------------------------------------------------------------------')

overall_accuracy = (test_data_set1_accuracy + test_data_set2_accuracy + test_data_set3_accuracy) / 3

print("\nOverall Accuracy = " + str("{:.00%}".format(overall_accuracy)) + "\n")