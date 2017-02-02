
from itertools import *
import time

def concProd(n, tup):
    ans = []
    for t in tup:
        ans.append(n*t)
    print ans
    answer = int("".join(map(str, ans)))
    return answer

def panDigs(n):
    pans = list(permutations(range(1,n+1)))

    ans = []
    for p in pans:
        ans.append(int("".join(map(str,p))))
    ans.sort()
    return ans

def isConcProd(p):
    for ind in range(1, 5):
        multiplier = 2
        ls = list(str(p))
        ori = int("".join( map(str,ls[:ind]) ) )
        n = int("".join( map(str,ls[:ind]) ) )
        nextInd = len(str(n))
##        print ori, n, nextInd, ls, multiplier
        if recurse(ori, n, nextInd, ls, multiplier):
            print "It's a concatenated product!", ori
            return True
    return False

def recurse(ori, n, nextInd, ls, multiplier):
    # Base Case
    if ls[0:nextInd] == ls:
        return True

    # Recursion
    n = ori*multiplier
    nLen = len(str(n))
    new = int("".join( ls[nextInd:nextInd+nLen] ) )
    if n == new:
        nextInd = nextInd + nLen
        multiplier += 1
        return recurse(ori, n, nextInd, ls, multiplier)
    else:
        return False

tStart = time.time()

pan9 = panDigs(9)
for p in pan9[::-1]:
    if isConcProd(p) == True:
        print "Answer:", p
        break
print "Time taken:", time.time() - tStart
