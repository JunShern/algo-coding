#Problem 27

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

def is_prime(ans):
    if ans in primes: return True
    else: return False
    
def largestn(a,b,n):
    ans = (n**2)+(a*n)+(b)
    
    if is_prime(ans):
        n += 1
        return largestn(a,b,n)
    else:
        return n-1

primes = findprimes(10000)
bprimes = findprimes(1000)
largest = []
for a in range(-999,1000):
    for b in bprimes:
        n = largestn(a,b,0)
        if n>50:
            largest.append([a,b,n])
        if n>10:
            print "n**2 + %in + %i" %(a,b)
            print n

big_n = 0
for l in largest:
    if l[2]>big_n:
        big_n = l[2]
        largeformula = l

product = largeformula[0]*largeformula[1] 
print "Ans:", product
        
