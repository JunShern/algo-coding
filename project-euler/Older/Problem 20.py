def factorial(n):
    factors = []
    while n!=0:
        factors.append(n)
        n -= 1

    answer = 1
    for n in factors:
        answer *= n
    return answer
        
def summate(answer):
    answer = str(answer)
    strdigits = list(answer)
    digits = []
    for s in strdigits:
        digits.append(int(s))
    return sum(digits)

n = int(raw_input("Which number? "))
answer = factorial(n)
print summate(answer)
