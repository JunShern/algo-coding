
def getLastTen(n):
    n = list(str(n))
    n = int("".join(n[-10:]))
    return n

def findPower(n,p):
    powerMax = p
    power = 1
    ans = 1
    while power <= powerMax:
        ans*=n
        ans = getLastTen(ans)
        power += 1
    return ans

ans = findPower(2,7830457)
ans = 28433*ans
ans += 1
print getLastTen(ans)
