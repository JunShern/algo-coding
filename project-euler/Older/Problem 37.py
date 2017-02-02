#Problem 37
#The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
#Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
#NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

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

def truncate(num):
    stages = []
    left_right = list(str(num))
    right_left = list(str(num))

    while len(left_right)>0:
        stages.append(int("".join(left_right)))
        left_right.pop(0)

    while len(right_left)>0:
        stages.append(int("".join(right_left)))
        right_left.pop(-1)

    return stages

def is_prime(stage):
    if stage in primes:
        return True
    else:
        return False
    
start = time.time()
primes = findprimes(1000000)

tprimes = []
for p in primes:
    if p<10:
        continue
    
    if len(tprimes)==11:
        print "Done!"
        break
    stages = truncate(p)

    is_tprime = True
    for s in stages:
        if is_prime(s):
            continue
        else:
            is_tprime = False
            break
    if is_tprime:
        print "Found one!", str(p)
        tprimes.append(p)

print sum(tprimes)

print "Runtime = " + str(time.time() - start)
