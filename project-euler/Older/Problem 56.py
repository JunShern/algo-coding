#Problem 56
#A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.
#Considering natural numbers of the form, ab, where a, b  100, what is the maximum digital sum?

def digitsum(num):
    digits = list(str(num))
    dsum = 0
    for d in digits:
        dsum += int(d)
    return dsum

maxdsum = 0
for a in range(1,100):
    for b in range(1,100):
        num = a**b
        dsum = digitsum(num)
        if dsum > maxdsum:
            print dsum
            maxdsum = dsum
print "Maximum digital sum:", maxdsum
