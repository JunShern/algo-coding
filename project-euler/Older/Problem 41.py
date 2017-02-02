# Problem 41
# We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
# What is the largest n-digit pandigital prime that exists?

from itertools import *

def primefilter(primes, d): #remove all multiples of d from primes
    for p in primes:
        if d>p or p<d*2:
            continue

        if p%d == 0 and p!=d:
            position = primes.index(p)
            primes.pop(position)
    return primes

def findprimes(maximum):
    primes = [2]
    for n in range(3, maximum, 2):
        primes.append(n)

    for d in primes:
        if d>maximum/2:
            return primes
        
        primes = primefilter(primes, d)
##        print "Remaining primes after removing multiples of %i: \n" %d, primes

    return primes

def is_prime(n):
    prime = False
    if n > 10000:
        prime = True
        for p in primes:
            if n % p == 0:
##                print "Divisible by", p
                prime = False
                return False
    if prime != False:
        return True

    if n in primes:
        return True
    else:
        return False

def findPP(n):
    ppList = []
    perms = list(permutations(range(1, n+1)))
##    print perms
    for p in perms:
        p = int("".join(map(str, p)))
        if is_prime(p):
            ppList.append(p)
    return ppList
        
primes = findprimes(10000)
answers = []
for n in range(1,10):
    pp = findPP(n)
    answers.append(pp)
##    print n, ":", pp

answers.sort()
answers[-1].sort()
print answers[-1][-1]
