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

def findRepeats(p):
    for n in nums:
        occurance = 0
        while n in nums:
            occurance += 1
            nums.remove(n)
        if occurance > 0:
            print n,"occurs",occurance,"times."

def replaceAll(num,inds,val): # replaces the values at the given positions with a value
    nums = list(str(num))
    for i in inds:
        nums.pop(i)
        nums.insert(val,i)
    return int("".join(nums))

primeList = primes(10000000)
print len(primeList)
startInd = primeList.index(56993)
##for p in primeList[startInd:] :
##    if findRepeats(p) != []

