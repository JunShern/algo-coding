
def sumdivs(n):
    divs = []
    for d in range(1, (n/2)+1):
        if n%d==0:
            divs.append(d)
    return sum(divs)

def check(num1, num2):
    if sumdivs(num1)==num2 and sumdivs(num2)==num1 and num1!=num2:
        print "%i and %i are amicable!" %(num1, num2)
        amicable.append(num1)
        amicable.append(num2)
    
amicable = []

for n in range(1,10000):
    if n%100==0:
        print n
    for m in range(n, n*2):
        if abs(m-n)>=n/2:
            break
        elif n>1000 and abs(m-n)>n/5:
            break
        elif abs(m-n)>500:
            break
        else:
            check(n,m)
print sum(amicable)
