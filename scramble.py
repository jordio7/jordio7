import random

punct = (".", ";", "!", "?", ",")
new_word = ""

file_name = input("Enter input file name:")

with open(file_name) as fin:
	for line in fin.readlines():

		for w in line.split():

			w1 = w
			if len(w) > 3:

				if w.endswith(punct):
					w1 = w[1:-2]
					w1 = random.sample(w1, len(w1))
					w1.insert(0, w[0])
					w1.append(w[-2])
					w1.append(w[-1])

				else:
					w1 = w[1:-1]
					w1 = random.sample(w1, len(w1))
					w1.insert(0, w[0])
					w1.append(w[-1])
			new_word += ''.join(w1) + " "

	print(new_word)
