
def triangle(n):
    answer = n*(n+1)/2
    return answer

def isNatural(n):
    if n%1 == 0 and n >= 0 :
        return True
    else:
        return False
    
def isPentagonal(n):
    ans = ( ((24*n)+1)**0.5 + 1)/6
    if isNatural(ans):
        return True
    else:
        return False

for n in range(1, 100000, 2):
    candidate = triangle(n)
    if isPentagonal(candidate):
        print candidate

