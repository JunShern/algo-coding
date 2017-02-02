#Problem 23
#A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
#A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
#As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24.
#By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
#Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.


#if a number is an abundant number, return True
def numtype(n):
    divs = []
    for d in range(1,n/2+1):
        if n%d==0:
            divs.append(d)
    if sum(divs)==n: #perfect num
        return False
    elif sum(divs)<n: #deficient num
        return False
    elif sum(divs)>n: #abundant num
        return True
    else:
        print "Something went wrong."

#create a list of abundant numbers
def createlist():
    abundantnums = []
    for n in range(1,28123+1):
        if numtype(n):
            abundantnums.append(n)
    print "Got all the abundant numbers!"
    return abundantnums

#create a list of all the possible sums of any two numbers in abundantnums
def createsums():
    sums = []
    for n in abundantnums:
        for m in abundantnums:
            sums.append(n+m)
    sums = sorted(sums)
    sums = list(set(sums)) #removes any duplicates in the list
    print "Got all the sums!"
    return sums

abundantnums = createlist()
sums = createsums()
notsums = []
for n in range(1, 28123+1):
    notsum = True
    for s in sums:
        if s>n:
            break
        if n==s:
            notsum = False
    if notsum:
        notsums.append(n)
        
print sum(notsums)
