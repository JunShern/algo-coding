# Problem 10
# By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
# What is the 10 001st prime number?

prime = [2]
limit = 2000000
for n in range(3, limit+2, 2):
    count = 0
    for x in prime:
##        print "Now evaluating %i divided by %i." %(n, x)
##        print "Primes are ", prime
        if n % x != 0 and n != prime[-1]:
            count += 1
##            print "Count is %i." %count
            if count == len(prime): 
                prime.append(n)
##                print "%i is a prime!" %n
        else:
            break
print "We've got them all!"

##Alternative Solution
##
##Here is my Python implementation using the Sieve of Eratosthenes (http://en.wikipedia.org/wiki/Sieve_of_eratosthenes) --
##
##
### -*- Python -*-
### Author: Baishampayan Ghose
##
##def primes(n):
##    '''
##    Generate primes using the sieve algorithm
##    '''
##    if n == 2:
##        return [2]
##    elif n < 2:
##        return []
##    s = range (3, n+1, 2)
##    mroot = n ** 0.5
##    half = ((n + 1) / 2) - 1
##    i = 0
##    m = 3
##    while m <= mroot:
##        if s:
##            j = (m * m - 3) / 2
##            s[j] = 0
##            while j < half:
##                s[j] = 0
##                j += m
##        i = i+1
##        m = 2 * i + 3
##    return [2] + [x for x in s if x]
##
##list = primes(200000) # generate a list of all primes below 2,00,000
##
##print list[10000]
##
##
##When executed, it took 0.007 sec on my machine. Pretty neat, huh?


