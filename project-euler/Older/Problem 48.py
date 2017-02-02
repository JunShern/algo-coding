#Problem 48
#The series, 1**1 + 2**2 + 3**3 + ... + 10**10 = 10405071317.
#Find the last ten digits of the series, 1**1 + 2**2 + 3**3 + ... + 1000**1000.

def selfpower(limit):
    powers = []
    for n in range(1, limit+1):
        powers.append(n**n)
    return sum(powers)

limit = int(raw_input("Limit: "))

ans = selfpower(limit) % 10000000000;

print ans
