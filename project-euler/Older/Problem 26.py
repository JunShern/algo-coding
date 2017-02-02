
def getdecimals(num):
    num = list(str(num))
    num.remove("0")
    num.remove(".")
    num = "".join(num)
    return num #such as 0123123123

def findcycle(num):
    #check if the number repeats itself
    sample = list(num)
    print "Decimals:", sample
    for n in sample:
        candidate = n 
        nposition = sample.index(n)
        sample.pop(nposition)
        repeat = False
        for p in sample:
            if p == candidate:
                repeat = True
        if repeat:
            #get the first cycle
            splice = sample[nposition:sample.index(candidate)]
            cycle = candidate + "".join(splice)
            length = len(cycle)
            
            #remove the first cycle from the sample
            for n in sample[:length-1]:
                sample.pop(0)

            #compare the remaining numbers in sample to cycle
            similar = True
            compare = list(cycle)
            index = 0
            for n in sample:
                if index>len(compare):
                    break
                if n != compare[0]:
                    similar = False
                index += 1
            if similar:
                print "It's a repeating cycle!", candidate, cycle

        sample.insert(nposition,candidate)        


##    
##    digits = num.split(first)
##    digits.remove("")
##    
##    newdigits = []
##    for n in digits:
##        x = list(n)
##        x.insert(0,first)
##        x = "".join(x)
##        newdigits.append(x)
##        print x
##
##    cycle = newdigits[0]
##    print "Cycle:", cycle
##    return cycle
##
for d in range(2,101):
    print "\n1/%i:" %d
    num = 1.0/d
    deci = getdecimals(num) 
    cycle = findcycle(deci)
    if cycle!=None:
        print cycle
