# Problem 76

import itertools

def splitList(array, points) :
	points.sort() ## Arrange the points in ascending order
	parts = []
	startP = 0
	for p in points:
		parts.append( array[startP:p] )
		startP = p
	if array[startP:] != [] :
		parts.append( array[startP:] )
	return parts
		
def waysToSum(num) :
	## Setup
	nDivs = num-1 ## Maximum number of numbers (num) can be split into
	array = [1 for n in range(0,num) ] ## Array of (num) 1's
	ways = []

	## Loop through all the possible ways to split the array into mini-array-sums
	possibleInds = [n for n in range(1,num) ]
	for d in range(1, nDivs+1) :
		print "Working on d = ", d
		## Use combinatorics to generate all possible divPoints
		if d == nDivs - 1 :
			divPointCombs = [ [n for n in range(1,d+1)] ]
		elif d == nDivs :
			divPointCombs = [ [n for n in range(1,d+1)] ]
		else : 
			divPointCombs = itertools.combinations(possibleInds, d)	
		for divPoints in divPointCombs :
			## itertools returns tuple; convert to list
			divPoints = list(divPoints)
			## split the array at given divPoints
			split = splitList(array, divPoints)
			## write a list of the sums of each part of (split)
			way = sorted( map( sum, split ) )
			if way not in ways :
				print way
				ways.append(way)
	
	return ways


num = 10
ways = waysToSum(num)
print "Number of ways to sum", num, "is", len(ways)
