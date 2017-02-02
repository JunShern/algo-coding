

def factorial(n):
    ans = 1
    for i in range(1, n+1):
        ans *= i
    return ans

def sumdigitfactorial(n):
    answers = []
    digits = list(str(n))
    for d in digits:
        answers.append(factorial(int(d)))
    return sum(answers)

def check_sdf(n):
    if sumdigitfactorial(n) == n and n!=1 and n!=2:
        return True
    else:
        return False

sdf = []
for n in range(1,1000001):
    if check_sdf(n)==True:
        print "%i is an SDF." %n
        sdf.append(n)
print sum(sdf)
    
