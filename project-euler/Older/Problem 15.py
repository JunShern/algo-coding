# Problem 15
# Starting in the top left corner of a 2*2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
# How many such routes are there through a 20*20 grid?

import time

val = 0

def value(x,y):
    # Establish Base Case
    if x == 0 or y == 0:
        return 1
    
    val = value(x-1, y) + value(x, y-1)
    
    return val

def numWays(sides):
    yVal = 0
    uplist = [1 for n in range(0,sides+1)]
    while yVal <= sides:
        if yVal + 1 > sides:
            break
        
##        print yVal, uplist
        
        nextlist = []
        for n in uplist:
            if len(nextlist) == 0:
                newNum = 1
            else:
                newNum = nextlist[-1] + n
            nextlist.append(newNum)
            
        uplist = nextlist

        yVal += 1

    return uplist[-1]

tStart = time.time()
print numWays(20)
print time.time() - tStart
