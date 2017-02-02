
def nextNum(num):
    num = map(int, list(str(num)))
    nextN = 0
    for n in num:
        nextN += n**2
    return nextN

def loopToEnd(num):
    path = [num]

    while num!= 1 and num!= 89:
        if num in list1:
            num = 1
            break
        if num in list89:
            num = 89
            break
        num = nextNum(num)
        path.append(num)
    
    if num == 1:
        for p in path:
            if p not in list1:
                list1.append(p)
    if num == 89:
        for p in path:
            if p not in list89:
                list89.append(p)
        
    return [num, path]

list1 = []
list89 = []
answer = 0
for n in range(1,10000000):
    if n%100000 == 0:
        print "Made it to", n
    ## print "%d ends as %d." %(n, loopToEnd(n))
    if loopToEnd(n)[0] == 89:
        answer += 1

print "GOT IT!", answer
