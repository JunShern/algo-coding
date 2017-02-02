# Project Euler Problem 1

# If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
# Find the sum of all the multiples of 3 or 5 below 1000.

def multlist(n):
	num = 0
	list = []
	while num < n:
		if num % 3 == 0 or num % 5 == 0:
			list.append(num)
		num += 1
	list.pop(0)
	return sum(list)

multlist(1000)

# alternative:
# print sum(set(range(0, 1000, 3) + range(0, 1000, 5)))
