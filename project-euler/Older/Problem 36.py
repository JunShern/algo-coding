#Problem 36
#The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
#Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
#(Please note that the palindromic number, in either base, may not include leading zeros.)

def is_palin(n):
    numbers = list(str(n))
    if len(numbers) % 2 == 0: #no problem with evenly-lengthed numbers
        pass
    else: #pop the middle number of oddly-lengthed numbers
        numbers.pop(len(numbers)/2)
        
    half1 = numbers[:len(numbers)/2]
    half2 = numbers[len(numbers)/2:]
    reversedhalf2 = half2[::-1]
    if half1 == reversedhalf2:
        return True
    else:
        return False

def createpalin(start, end):
    palins = []
    for n in range(start, end):
        if is_palin(n):
            palins.append(n)
    return palins

def divide(num, divisor):
    quotient = 0
    count = 0
    while count+divisor<=num:
        quotient += 1
        count += divisor
    remainder = num - count
    return quotient, remainder

def convert2base(n, base):
    remainders = []

    quotient = n
    while quotient >= base:
        results = divide(quotient, base)
        quotient = results[0]
        remainder = results[1]
        remainders.insert(0, str(remainder))
##        print "Quotient: %i, Remainder: %i" %(quotient, remainder)
    remainders.insert(0, str(quotient))
    answer = "".join(remainders)
    return answer

palins = createpalin(1,1000001)
doublepalin = []
for p in palins:
    binary = convert2base(p, 2)
    if is_palin(binary):
        print "%i and %s are both palindromes!" %(p, binary)
        doublepalin.append(p)
    
print sum(doublepalin)
