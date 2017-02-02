from math import *

def triangle(n):
	return n*(n+1)/2

def square(n):
	return n*n

def pentagonal(n):
	return n*(3*n - 1)/2

def hexagonal(n):
	return n*(2*n - 1)

def heptagonal(n):
	return n*(5*n - 3)/2

def octagonal(n):
	return n*(3*n - 2)

def polygonal(p, n):
	if p == 3:
		return triangle(n)
	elif p == 4:
		return square(n)
	elif p == 5:
		return pentagonal(n)
	elif p == 6:
		return hexagonal(n)
	elif p == 7:
		return heptagonal(n)
	elif p == 8:
		return octagonal(n)
	else:
		print "Not a valid value for p."

def populate(listP, p):
	val = 1
	n = 1
	i = 0
	while val < 1000:
		val = polygonal(p,n)	
		n += 1
	while val < 10000:
		val = polygonal(p,n)
		listP.append(val)
		i += 1
		n += 1
	listP.remove(listP[-1])
		
def separate(listP):
	for i in range(0,len(listP)) :
		half1 = str(listP[i])[:2]
		half2 = str(listP[i])[2:]
		listP[i] = [ half1, half2 ]
 
def listN(N):
	if N == 3 : return list3
	elif N == 4: return list4
	elif N == 5: return list5
	elif N == 6: return list6
	elif N == 7: return list7
	elif N == 8: return list8
	else: print "Error in listN!"

def getMatches(tail, listN):
	tails = []
	for match in listN:
		if tail == match[0]:
			tails.append(match[1]) ## Append the tail of the match
	return tails

def attack(tail, lists, homeN, answer):
#	print (tail),
	funLists = list(lists) ## Make a copy of the list for this function
	funLists.remove(homeN) ## Remove the list we got the last tail from from the search field

	answer += int(tail) + int(tail)*100

	## Base Case
	if len(funLists) == 0:
		if tail == winner:
#			print "WINNER"
			return answer
		else:
#			print "Matched all but last! :("
			return -1

	## Recursion
	i = 0
	while len(funLists) > 0:
		## Test if there are any more matches to be made
		none = True
		for l in funLists:
			if len(getMatches(tail,listN(l))) != 0:
				none = False
		if none:
#			print "No more matches in any of the lists."
			return -1

		N = funLists[i]
#		print "Trying to match", tail, "with N =", N
		tails = getMatches(tail, listN(N))
		if len(tails) == 0:
#			print "No matches."
			continue ## Sorry, it didn't work out
#		print "%d match(s)." %(len(tails))
		for t in tails:
			ans = attack(t, funLists, N, answer)
#			print "Coming out of attack()."
			if ans != -1:
				return ans

		## Iterate through funList
		i += 1
		if i == len(funLists):
			i = 0


## Make lists of all the four digit polygonal numbers
list3 = []
populate(list3,3)
separate(list3)

list4 = []
populate(list4,4)
separate(list4)

list5 = []
populate(list5,5)
separate(list5)

list6 = [] 
populate(list6,6)
separate(list6)

list7 = []
populate(list7,7)
separate(list7)

list8 = [] 
populate(list8,8)
separate(list8)

## Compare, brute force method
for tri in list3:
	print tri
	lists = [3,4,5]
	tail = tri[1]
	winner = tri[0]
	answer = 0
	answer = attack(tail, lists, 3, answer)

	print "Answer:", answer


for N in range(3,6):
	print listN(N)




