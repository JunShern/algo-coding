# Problem 9
# A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,

# a**2 + b**2 = c**2
# For example, 3**2 + 4**2 = 9 + 16 = 25 = 5**2.

# There exists exactly one Pythagorean triplet for which a + b + c = 1000.
# Find the product abc.

def getans():
    for a in range(1, 300):
        for b in range(a + 1, 500):
            for c in range(b + 1, 500):
##                print a, b, c, a + b + c
                if triplets(a, b, c) == True:
                    if sumthousand(a, b, c) == True:
                        print "The product of %i, %i and %i is %i." %(a, b, c, a * b * c)
                        return
                    else:
                        break

def triplets(a, b, c):
    if a**2 + b**2 == c**2:
        print "These are Pythagorean triplets: %i, %i, %i" %(a, b, c)
        return True
    else:
##        print "Not Pythagorean triplets."
        return False

def sumthousand(a, b, c):
    if a + b + c == 1000:
        print "Got it! The sum of %i, %i and %i is 1000." %(a, b, c)
        return True
    else:
        print "Nope, the sum of %i, %i and %i is %i." %(a, b, c, a + b + c)
        return False

getans()
