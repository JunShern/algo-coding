# Problem 4

# A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91*99.
# Find the largest palindrome made from the product of two 3-digit numbers.

def check(n):
    numbers = list(str(n))
    if len(numbers) % 2 == 0:
        pass
    else:
        return
    half1 = numbers[:len(numbers)/2]
    half2 = numbers[len(numbers)/2:]
    reversedhalf2 = half2[::-1]
    if half1 == reversedhalf2:
        return True
    else:
        return False

palindromes = []
for x in range(100, 1000):
    for y in range(100, 1000):
        ans = x * y
        if check(ans):
            palindromes.append(ans)
print max(palindromes)
		
