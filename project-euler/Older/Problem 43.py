from itertools import *
import time

def panDigs(n):
    pans = list(permutations(range(0,n+1)))

    ans = []
    for p in pans:
        if p[0] == 0:
            continue
        ans.append(int("".join(map(str,p))))
    ans.sort()
    return ans

def getSubs(n):
    nums = list(str(n))
    subs = []
    ind = 1
    while ind + 3 <= len(nums):
        subs.append(int("".join(nums[ind:ind+3])))
        ind += 1
    return subs

def test(p):
    subs = getSubs(p)
    count = 0
    divisors = [2,3,5,7,11,13,17]
    for s in subs:
        if s%divisors[count] != 0:
            return False
        count += 1
    return True

tStart = time.time()

pans = panDigs(9)
print "Got pans!"

answers = []
for p in pans:
    if test(p) == True:
        print "Got one!", p
        answers.append(p)

print sum(answers)
print "Time taken:", time.time() - tStart
