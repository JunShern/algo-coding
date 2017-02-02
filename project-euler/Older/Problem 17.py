#Problem 17
#If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
#If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
#NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

def translate(num):
    #first let's break down each number into a list of digits
    strdigits = list(str(num))
    digits = []
    for n in strdigits:
        digits.append(int(n))
        
    if len(digits)==4:
        name.append("onethousand")
    if len(digits)>=3:
        seconddigit(digits)
    if len(digits)>=2:
        thirddigit(digits)
    if len(digits)>=1:
        lastdigit(digits)
    else:
        print "Something went wrong."

    number = "".join(name)
    return number

#handle three-digit numbers
def seconddigit(digits):
    if digits[-3]==1:
        name.append("onehundred")
    elif digits[-3]==2:
        name.append("twohundred")
    elif digits[-3]==3:
        name.append("threehundred")
    elif digits[-3]==4:
        name.append("fourhundred")
    elif digits[-3]==5:
        name.append("fivehundred")
    elif digits[-3]==6:
        name.append("sixhundred")
    elif digits[-3]==7:
        name.append("sevenhundred")
    elif digits[-3]==8:
        name.append("eighthundred")
    elif digits[-3]==9:
        name.append("ninehundred")
    if digits[-1]!=0 or digits[-2]!=0:
        name.append("and")
            
#handle two-digit numbers
def thirddigit(digits):
    if digits[-2]==1: #special case for numbers 10-19
        if digits[-1]==0:
            name.append("ten")
        elif digits[-1]==1:
            name.append("eleven")
        elif digits[-1]==2:
            name.append("twelve")
        elif digits[-1]==3:
            name.append("thirteen")
        elif digits[-1]==4:
            name.append("fourteen")
        elif digits[-1]==5:
            name.append("fifteen")
        elif digits[-1]==6:
            name.append("sixteen")
        elif digits[-1]==7:
            name.append("seventeen")
        elif digits[-1]==8:
            name.append("eighteen")
        elif digits[-1]==9:
            name.append("nineteen")
    elif digits[-2]==2:
        name.append("twenty")
    elif digits[-2]==3:
        name.append("thirty")
    elif digits[-2]==4:
        name.append("forty")
    elif digits[-2]==5:
        name.append("fifty")
    elif digits[-2]==6:
        name.append("sixty")
    elif digits[-2]==7:
        name.append("seventy")
    elif digits[-2]==8:
        name.append("eighty")
    elif digits[-2]==9:
        name.append("ninety")
        
#handle single-digit numbers
def lastdigit(digits):
    if len(digits)==1 or digits[-2]!=1 :
        if digits[-1]==1:
            name.append("one")
        elif digits[-1]==2:
            name.append("two")
        elif digits[-1]==3:
            name.append("three")
        elif digits[-1]==4:
            name.append("four")
        elif digits[-1]==5:
            name.append("five")
        elif digits[-1]==6:
            name.append("six")
        elif digits[-1]==7:
            name.append("seven")
        elif digits[-1]==8:
            name.append("eight")
        elif digits[-1]==9:
            name.append("nine")

name = []
lengths = []
for n in range(1,1001):
    number = translate(n)
    print number
    print len(number)
    lengths.append(len(number))
    name = []
print sum(lengths)

    
