import time

def primes(n): 
        if n==2: return [2]
        elif n<2: return []
        s=range(3,n+1,2)
        mroot = n ** 0.5
        half=(n+1)/2-1
        i=0
        m=3
        while m <= mroot:
                if s[i]:
                        j=(m*m-3)/2
                        s[j]=0
                        while j<half:
                                s[j]=0
                                j+=m
                i=i+1
                m=2*i+3
        return [2]+[x for x in s if x]

def findPFs(n):
    if n in primeList:
        return [1]
    primeFactors = []
    
    ind = 0
    p = primeList[ind]
    while p <= n:
        ind += 1
        if n%p==0:
            if p not in primeFactors:
                primeFactors.append(p)
            ind = 0
            n = n/p
            if n == 1:
                return primeFactors
        p = primeList[ind]
##    print "The number", n, "is indivisible by primes."

tStart = time.time()
primeList = primes(10000000)
print "Got primes!"
n = 2
consec = 0
nums = []
while consec!=4:
    PFs = findPFs(n)
    if len(PFs) == 4:
        print n, PFs
        nums.append(n)
        consec += 1
    else:
        consec = 0
        nums = []
    n += 1
print nums

print "Time taken:", time.time() - tStart
