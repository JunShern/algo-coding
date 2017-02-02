#Problem 50
#The prime 41, can be written as the sum of six consecutive primes:
#41 = 2 + 3 + 5 + 7 + 11 + 13
#This is the longest sum of consecutive primes that adds to a prime below one-hundred.
#The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
#Which prime, below one-million, can be written as the sum of the most consecutive primes?

import time

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

def getchainlength(p):
    if p == primes[-1]:
        return 1
    p1 = primes.index(p)
    p2 = 600

    primesums = []
    while p2>p1:
        terms = primes[p1:p2]
        
        if sum(terms) in primes:
            return len(terms)
        terms.append(primes[p2])
        p2 -= 1
    else:
        return 1

tStart = time.time()

primes = findprimes(1000000)

print "Got primes!"
print "Time:", time.time()-tStart

longest = 0
for p in primes[0:600]: #any bigger than the 600th prime, the sums would be larger than a million
    length = getchainlength(p)
    if length>longest:
        longest = length
        longsum = sum(primes[primes.index(p) : primes.index(p)+length])
        print p, length, longsum
print longsum
print "Time:", time.time()-tStart 

