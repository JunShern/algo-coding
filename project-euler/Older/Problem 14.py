#Problem 14
#The following iterative sequence is defined for the set of positive integers:
#n >>> n/2 (n is even)
#n >>>  3n + 1 (n is odd)
#Using the rule above and starting with 13, we generate the following sequence:
#13  40  20  10  5  16  8  4  2  1
#It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
#Which starting number, under one million, produces the longest chain?
#NOTE: Once the chain starts the terms are allowed to go above one million.

def collatz(n):
    chain = []
    while n!= 1:
        chain.append(n)
        if n%2==0:
            n /= 2
        else:
            n = 3*n+1
    chain.append(1)
    return chain

chain = []
for n in range(50000,1000000):
    new = collatz(n)
    if len(new)>len(chain):
        chain = new
        print "%i has a chain length of %i." %(n, len(chain))
    
