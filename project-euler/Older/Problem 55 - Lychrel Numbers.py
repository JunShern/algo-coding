# Problem 55

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
    
def reverseNadd(n):
    n = list(str(n))
    rev = list(reversed(n))
    n = int("".join(n))
    rev = int("".join(rev))
    
    ans = n + rev
    return ans
    
def is_Lychrel(n, count):
    n = reverseNadd(n)
    count += 1
    if count > 50:
        return True

    if is_palin(n):
##        print "%i produced a palindrome after %i iterations." %(n, count)
        return False
    else:
        return is_Lychrel(n, count)

numOfLychrels = 0
for n in range(1,10000):
    if is_Lychrel(n, 0):
        print "%i is a Lychrel number!" %n
        numOfLychrels += 1

print "Finally, we have our answer:", numOfLychrels
