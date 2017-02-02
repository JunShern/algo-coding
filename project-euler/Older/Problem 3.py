# Problem 3
# The prime factors of 13195 are 5, 7, 13 and 29.
# What is the largest prime factor of the number 600851475143 ?
import time
t0 = time.clock()
import math
## Get all factors of 600851475143
factors = []
for num in xrange(1, int(math.sqrt(600851475143L)), 2): # take steps of 2 since all even numbers are not prime(except 2)
    if 600851475143L % num == 0:
        factors.append(num)

## Get the factors of 600851475143 which neither have the value of nor are divisible by 2, 3, 5 or 7
almostprime = []
for n in factors:
    if n != 1 and n % 2 != 0 and n % 3 != 0 and n % 5 != 0 and n % 7 != 0 or n == 2 or n == 3 or n == 5 or n == 7:
	    almostprime.append(n)

## Find out which are not primes by checking if any almostprimes are divisible by smaller almostprimes
notprime = []

def check(bignum, smallnum):
    if bignum % smallnum != 0:
        return True
    else:
        return False

bignum = 1
while bignum < len(almostprime):
    for smallnum in range(0, bignum):  
        if check(almostprime[bignum], almostprime[smallnum]) == False:
            print "%i is divisible by %i and therefore it is not a prime number." %(almostprime[bignum], almostprime[smallnum])
            if len(notprime) == 0 or almostprime[bignum] != notprime[-1]:
                notprime.append(almostprime[bignum])
    bignum += 1

## almostprimes - notprimes = primes. LET'S GO!
prime = []
for n in notprime:
    almostprime.remove(n)
prime = almostprime
print "WE'RE READYYYY! JUST ASK FOR PRIME!"
t1 = time.clock()
timetaken = t1 - t0
print "Primes: ", prime
print "Time taken was %i." %timetaken
# This could be useful for future reference

##>>> for n in range(2, 10):
##...     for x in range(2, n):
##...         if n % x == 0:
##...             print n, 'equals', x, '*', n/x
##...             break
##...     else:
##...         # loop fell through without finding a factor
##...         print n, 'is a prime number'
##...
##2 is a prime number
##3 is a prime number
##4 equals 2 * 2
##5 is a prime number
##6 equals 2 * 3
##7 is a prime number
##8 equals 2 * 4
##9 equals 3 * 3
