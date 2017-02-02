# Problem 33
# The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
# We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
# There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
# If the product of these four fractions is given in its lowest common terms, find the value of the denominator.


from fractions import Fraction
import time

def test(num, den):
    cancel = False
    for n in list(str(num)):
        if n in list(str(den)):
            cancel = n

    if cancel != False:
##        print "Passed first test", [num , den]
        if int(cancel) == 0:
##            print "Trivial!"
            return False
        
        ans = float(num)/float(den)
        
        cnum = list(str(num))
        cnum.remove(cancel)
        cden = list(str(den))
        cden.remove(cancel)

        cnum = float(cnum[0])
        cden = float(cden[0])

        try:
            cnum/cden == ans
        except ZeroDivisionError:
            return False

        if cnum/cden == ans:
            return True
        else:
            return False
    else:
        return False

tStart = time.time()

answers = []
for num in range(10, 100):
    for den in range(num+1, 100):
        if test(num, den) == True:
            answers.append( [num, den] )
##            print "Got one!", [num, den]

numAns = 1
denAns = 1
for f in answers:
    numAns *= f[0]
    denAns *= f[1]

##print numAns, denAns
print Fraction(numAns, denAns)
print "Time taken:", time.time() - tStart 
