# Welcome back to python! :)

# Problem 18 - Maximum path sum

fin = open('problem18data.txt', 'r')

pyramid = []
for line in fin: 
	numbers = line.split()
	numbers = map(int, numbers)
	pyramid.append(numbers)

while len(pyramid) > 1:
	lineLen = len(pyramid[-2])
	for i in range(0, lineLen):
		if pyramid[-1][i] > pyramid[-1][i+1] :
			pyramid[-2][i] += pyramid[-1][i]
		else :
			pyramid[-2][i] += pyramid[-1][i+1]
	pyramid.pop()

print pyramid
