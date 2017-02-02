#Problem 35
#The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
#There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
#How many circular primes are there below one million?

def primefilter(primes, n): #remove all multiples of n from primes
    for p in primes:
        if n>p or p<n*2:
            continue
##        print str(p), str(n)

        if p%n == 0 and p!=n:
            position = primes.index(p)
            primes.pop(position)
    return primes

def findprimes(maximum):
    primes = list(range(2, maximum))
    for n in primes:
        if n>primes[-1]/2:
            return primes
        
        primes = primefilter(primes, n)
##        print "Remaining primes after removing multiples of %i: \n" %n, primes

    return primes

def rotations(p):
    digits = list(str(p))
    rotations = []
    for d in digits:
        rotations.append("".join(digits))
        digit = digits.pop(0)
        digits.append(digit)
    return rotations

def is_prime(r, primes):
    for p in primes:
        if p > int(r)/2:
            break
        if int(r)%p == 0:
            return False
    return True

primes = findprimes(1000000)
print "Got all the primes, sir!"
circularprimes = []
for p in primes:
    is_circularprime = True
    rotation = rotations(p)
    for r in rotation:
        if is_prime(r, primes) == False:
            is_circularprime = False
            break

    if is_circularprime:
        print "%i is a circular prime!" %p
        circularprimes.append(p)

print len(circularprimes)

"""
From the Forum
1) Get the single digit ones directly.
2) We know that the numbers have to end in 1,3,7,9 (except for the single digit ones).
Also, all primes are of the form 
6n-1 or 6n+1.
Therefore, given an ending digit and the reminder when divided by 6,
we can find all the possible ending digits that can be prime in a decade.
For example, if you divide 11 by 6, it gives a reminder of 5.
This means, than 11 is of the form 6n-1. Therefore, possible primes are 11,13,17,19.
I leave it upto the reader to figure out the other possibilities.
3) Once you have seen a sequence with a given first digit,
you never have to use that digit again for a given number of digits in a number.
For example, for 2 digit numbers, once you have finished 11 to 19,
you never have to use 1 again because you have seen all 2 digit numbers that contain a 1 and can possibly be prime.
"""
