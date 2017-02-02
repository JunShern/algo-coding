# Problem 5
# 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
# What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
    
def check(n, divisor):
    conditionspassed = 0 # need to be divisible by all numbers from 2 to 20 so 19 conditions
    while divisor <= 20:
        if n % divisor == 0:
            conditionspassed += 1 
            if conditionspassed == 19:
                print "We found it! The number is %i." %n
                found = True
        else:
            break
        divisor += 1

## Program starts here
found = False
for n in range(20, 1000000000, 20):
    divisor = 2
    check(n, divisor)
    if found == True:
        break
    else:
        print found
print "We've finally escaped the loop."


    
