import math
import string
import sys
import matplotlib.pyplot as plt

translation_table = str.maketrans(string.punctuation+string.ascii_uppercase," "*len(string.punctuation)+string.ascii_lowercase)

def get_words_from_line_list(text):
	text = text.translate(translation_table)
	word_list = text.split()
	return word_list

def count_frequency(word_list):
	Dictionary = {}
	for word in word_list:
		if word in Dictionary:
			Dictionary[word] = Dictionary[word] + 1
		else:
			Dictionary[word] = 1
	return Dictionary

def word_frequencies(filename):
	f=open(filename,'r')
	line_list = f.read()
	word_list = get_words_from_line_list(line_list)
	freq_mapping = count_frequency(word_list)
	return freq_mapping

def dotProduct(D1, D2):
	Sum = 0.0
	for word in D1:
		if word in D2:
			Sum += (D1[word] * D2[word])
	return Sum

def cosine_similarity(D1, D2):
	numerator = dotProduct(D1, D2)
	denominator = math.sqrt(dotProduct(D1, D1)) * math.sqrt(dotProduct(D2, D2))
	return (numerator/denominator)

#Function to plot the graph for frequency of words
def graph_plot(sorted_word_list, doc_word_list, doc_number, colour):
	count = 0
	for word in sorted_word_list.keys():
		plt.bar(count, doc_word_list.get(word,0), color = colour, width = 0.5)
		count += 2
	
	plt.suptitle("Words in doc" + str(doc_number) + ".txt", fontweight = "bold")
	plt.xticks([2*i for i in range(len(sorted_word_list.keys()))], sorted_word_list.keys(), rotation=90)
	plt.xlabel("Words in doc" + str(doc_number) + ".txt", fontweight = "bold")
	plt.ylabel("Frequency", fontweight = "bold")
	plt.show()

sorted_word_list_1 = word_frequencies('doc1.txt')
sorted_word_list_2 = word_frequencies('doc2.txt')
sorted_word_list = {**sorted_word_list_1, **sorted_word_list_2}
distance = cosine_similarity(sorted_word_list_1, sorted_word_list_2)
print("\n\tCOSINE SIMILARITY = % 0.5f"% distance)
print("\n\tCOSINE DISTANCE = % 0.5f\n"% (1-distance))

# Code for Plot
graph_plot(sorted_word_list, sorted_word_list_1, 1, 'blue')
graph_plot(sorted_word_list, sorted_word_list_2, 2, 'red')