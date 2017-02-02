#Problem 44 - Pentagonal Numbers

import time
from itertools import *

def pent(num):
    ans = num*(3*num - 1)/2
    return ans

def isNatural(n):
    if n%1 == 0 and n >= 0 :
        return True
    else:
        return False
    
def is_pent(p):
    ans = ( ((24*p)+1)**0.5 + 1)/6 # Formula to test for pentagonal numbers
    if isNatural(ans):
        return True
    else:
        return False
               
def sumdiff(p1, p2):
    if is_pent(p1+p2) and is_pent(abs(p1-p2)):
        return True
    else:
##        if is_pent(p1+p2):
##            print "Only sum is pentagonal."
##        elif is_pent(abs(p1-p2)):
##            print "Only difference is pentagonal."
        return False

def pentsUpTo(n):
    count = 1
    ls = []
    while count<n+1 :
        ls.append(pent(count))
        count += 1
    return ls

#Start here
tStart = time.time()
pentList = pentsUpTo(5000)
pairs = list(permutations(pentList, 2))
for pair in pairs:
    is_answer = sumdiff(pair[0], pair[1])
    if is_answer:
        print "Got it!", pair[1], "-", pair[0], "=", pair[1]-pair[0]
        break

print "Time:", time.time() - tStart
