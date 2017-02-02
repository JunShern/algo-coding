from math import *

def sieve(maxNum) :
    primes = [0 for n in range(0, maxNum) ]
    primes[0] = 0
    primes[1] = 0
    primes[2] = 1
    for num in range(3, maxNum, 2) :
        primeness = 1
        for div in range(2, int(sqrt(num)) + 1 ) :
            if num % div == 0 :
                primeness = 0
        if primeness == 1 :
            primes[num] = 1
    return primes

primes = sieve(100)

num = 0
for p in primes :
    if p == 1 :
        print "%d is a prime!" %(num)
        strnum = str(num)
        length = len(strnum)
        for l in range(1,length) :
            
    num += 1


