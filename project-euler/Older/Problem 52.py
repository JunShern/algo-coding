#Problem 52
#It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
#Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

import time

def checklen(n):
    length = len(str(n))
    if length == len(str(n*6)):
        return True
    else: return False

def roundup(n):
    length = len(str(n))
    rnum = "1" + "0"*length
    return int(rnum)

def checkdigits(n):
    digits = list(str(n))
    sorted_digits = sorted(digits)

    for m in range(2,7):
        mdigits = sorted(list(str(n*m)))
        if mdigits == sorted_digits:
            continue
        else:
            return False
        
    return True 

tStart = time.time()

n = 0
samedigits = False
while samedigits == False:
    n += 1
    if checklen(n)==False:
        n = roundup(n)
        continue
    samedigits = checkdigits(n)
    if samedigits==True:
        print "Found it!", n

print "Time:", time.time() - tStart
