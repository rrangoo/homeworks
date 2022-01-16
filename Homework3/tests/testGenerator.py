from random import randint

name = "_test_random.txt"
names = []
for i in range(1, 6, 1):
	names.append(str(i) + name)
	
for n in names:
	f = open(n, 'w')
	for i in range(10000):
		s = ""
		s += str(randint(1, 3)) + " " + str(randint(1, 100)) + " " + str(randint(1, 100)) + " " + str(randint(1, 100))
		f.write(s + "\n")
