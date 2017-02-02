import time
from itertools import *

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

def find4digPrimes():
    fourDigPrimes = []
    for p in primeList:
        if p>=10000:
            break
        if p>=1000 and p<10000:
            fourDigPrimes.append(p)
    return fourDigPrimes

def findPerms(c):
    cList = list(str(c))
    allPerms = list(permutations(cList))
    perms = []
    for p in allPerms:
        p = int("".join(p))
        if p not in perms and p>=1000 and p in candidates:
            perms.append(p)
    return sorted(perms)

def checkForSequence(perms):
    halfLen = len(perms)/2
    while len(perms)>0:
        for p in perms:
            if perms.index(p)==0:
                continue
            difference = p - perms[0]
            if (p + difference) in perms:
                print perms[0], p, p+difference
                return True
        perms.pop(0)
    return False
        
primeList = primes(10000)
candidates = find4digPrimes()
count = 0
for c in candidates:
    perms = findPerms(c)
    if checkForSequence(perms):
        count += 1
print "We're done!"
