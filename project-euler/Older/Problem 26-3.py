
def getdecimals(num):
    num = list(str(num))
    num.remove("0")
    num.remove(".")
    num = "".join(num)
    return num #such as 0123123123

def findrepeats(decimals, ind):
    decimals = list(decimals)
    repeats = [ind]
    candidate = decimals.pop(ind) #no need to insert it back later because decimals won't be used anymore

    index = 1 #1 because 0 is the candidate
    for r in decimals:
        if candidate == r:
            repeats.append(index)
        index += 1
    print repeats
    return repeats

def findcycle(deci, repeats):
    for divs in range(1, len(repeats) ):
        index = 0

        if index+divs+divs>=len(repeats):
            cycle = deci[ repeats[index] : repeats[index+divs] ]
            print "Cycle:", cycle
            index += divs
            newcycle = deci[ repeats[index] : repeats[index+divs] ]
            print "Newcycle:", newcycle

            repetition = False
            ind = 0
            for n in cycle:
                if ind>=len(newcycle):
                    break
                elif ind<len(newcycle) and n == newcycle[ind]:
                    repetition = True
                elif n != newcycle[ind]:
                    repetition = False
                    break

                ind += 1
            if repetition:
                return cycle
            
        else:
            while (index)<len(repeats):
                cycle = deci[ repeats[index] : repeats[index+divs] ]
                print "Cycle:", cycle
                index += divs
                newcycle = deci[ repeats[index] : repeats[index+divs] ]
                print "Newcycle:", newcycle

                repetition = False
                ind = 0
                for n in cycle:
                    if ind>=len(newcycle):
                        break
                    elif ind<len(newcycle) and n == newcycle[ind]:
                        repetition = True
                    elif n != newcycle[ind]:
                        repetition = False
                        break

                    ind += 1
                if repetition:
                    return cycle

def getlongest(cycles):
    strcycles = []
    for c in cycles:
        strcycles.append(str(c))
    return max(strcycles)



# Start here
longestcycles = []
champion = "0"
for d in range(2,1001):
    num = 1.0/d
    deci = getdecimals(num)
    print "\nDeci:", deci

    cycles = []
    #check for repeats of each decimal
    for n in deci:
        repeats = findrepeats(deci, deci.index(n))

        cycle = findcycle(deci, repeats)
        print cycle
        if cycle != "None":
            cycles.append(cycle)
            break
        else:
            deci.pop(0)
        
    longest = getlongest(cycles)
    print "1.0/%i, %s, %s" %(d, deci, longest)
    if longest != "None":
        identifier = "%i => %s" %(d, longest)
        longestcycles.append(identifier)
        
        if len(longest)>len(champion):
            champion = longest
            print "1.0/%i, %s, %s" %(d, deci, longest)


    

    
