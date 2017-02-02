
def fibonacci(numdigits):
    num1 = 1
    newfib = 1
    fib = [1, 1]
    term = 2
    while digitlen(fib[-1]) < numdigits:
        num2 = newfib
        newfib = num1 + num2
        fib.append(newfib)
        term += 1
        
        num1 = num2
        
        if digitlen(fib[-1])==numdigits:
            return term

def digitlen(num):
    num = str(num)
    digits = list(num)
    return len(digits)

n = int(raw_input("n: "))
print fibonacci(n)


