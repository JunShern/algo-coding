# Problem 32
# We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.
# The product 7254 is unusual, as the identity, 39*186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
# Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
# HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

from itertools import *
import time

def tuple2int(tup):
    ans = int(''.join(map(str,tup)))
    return ans

def spliceInt(n, a, b):
    ls = list(str(n))
    ans = int("".join(ls[a:b]))
    return ans
    
def check(n):
    # check _ times ____ 
    digit1 = spliceInt(n,0,1)
    digit4_1 = spliceInt(n,1,5)
    digit4_2 = spliceInt(n,5,10)

    if digit1 * digit4_1 == digit4_2:
        print "%i * %i == %i" %(digit1, digit4_1, digit4_2)
        return digit4_2

    # check __ times ___
    digit2 = spliceInt(n,0,2)
    digit3 = spliceInt(n,2,5)
    digit4 = spliceInt(n,5,10)

    if digit2 * digit3 == digit4:
        print "%i * %i == %i" %(digit2, digit3, digit4)
        return digit4
    else:
        return None

tStart = time.time()

# creates a list of tuples     
sample = list( permutations(range(1,10)) )

# converts tuples to integers
sample = map(tuple2int, sample)

answers = []
count = 0
for n in sample:
    c = check(n)
    if c != None:
        print "Got one!", c
        if c not in answers:
            answers.append(c)
    count += 1

print sum(answers)
print "Time taken:", time.time() - tStart
