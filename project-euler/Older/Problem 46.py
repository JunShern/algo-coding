
def primes(n): 
    if n==2: return [2]
    elif n<2: return []
    s=range(3,n+1,2)
    mroot = n ** 0.5
    half=(n+1)/2-1
    i=0
    m=3
    while m <= mroot:
            if s[i]:
                    j=(m*m-3)/2
                    s[j]=0
                    while j<half:
                            s[j]=0
                            j+=m
            i=i+1
            m=2*i+3
    return [2]+[x for x in s if x]

def goldbach(p,s):
    ans = p + 2*(s**2)
    return ans

def odd_comp(lim):
    oddcoms = []
    for n in range(3,lim,2):
        if n in primelist:
            continue
        else:
            oddcoms.append(n)
    return oddcoms

primelist = primes(1000000)
oddcoms = odd_comp(100000)
print "Got primes and odd composites!"

gold_nums = []
for p in primelist:
    if p>10000:
        break
    for s in range(1,100):
        gold = goldbach(p,s)
        if gold not in gold_nums:
            gold_nums.append(gold)
            gold_nums.sort()

for oc in oddcoms:
    if oc not in gold_nums:
        print "Found it!:", oc
        break
