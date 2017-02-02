# Problem 76

def intToList(num) :
	num = str(num)
	return map(int, list(num))

def isAscending(list) :
	previous = 0
	for l in list :
		if l < previous :
			return False
		previous = l
	return True

def increment(number) :
	number += 1
	test = intToList(number)
	while not (isAscending(test)) :
		number += 1
		test = intToList(number)
	return number

def waysToSum(num) :
	## Setup
	nDivs = num-1 ## Maximum number of numbers (num) can be split into
	array = [1 for n in range(0,num) ] ## Array of (num) 1's
	ways = []

	## Loop through all the possible ways to split the array into mini-array-sums
	possibleInds = [n for n in range(1,num) ]
	for d in range(1, nDivs+1) :
		## Produce all possible (elements) lists that sum to (num), where len(elements) is d+1
		print "Working on d = ", d
		## Make an integer with all digits 1, and length (d)
		number = 0
		for p in range(0,d) :
			number += pow(10, p)
		## Use number as the first (d) elements
		elements = intToList(number) 
		## Append the last element
		elements += [num - sum(elements)]

		while (elements[0] <= num/(d+1) ) :
			## Use number as the first (d) elements
			elements = intToList(number) 
			## Append the last element
			elements.append(num - sum(elements))
			if elements[-1] < elements[-2] : 
				number = increment(number)
				continue
			## Check if it sums to (num)
			if sum(elements) == num :
				print elements
				ways.append(elements)
			
			## Increment number
			number = increment(number)
			
	return ways


num = 10
ways = waysToSum(num)
print "Number of ways to sum", num, "is", len(ways)
