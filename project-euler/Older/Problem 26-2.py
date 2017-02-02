#Problem 26
#A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
#1/2	= 	0.5
#1/3	= 	0.(3)
#1/4	= 	0.25
#1/5	= 	0.2
#1/6	= 	0.1(6)
#1/7	= 	0.(142857)
#1/8	= 	0.125
#1/9	= 	0.(1)
#1/10	= 	0.1
#Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
#Find the value of d  1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.



from decimal import *

#given a float, return a string of only the numbers after the decimal point
def getdecimals(num):
##    print "Getting decimals..."
    num = list(num)
    num.remove("0")
    num.remove(".")
    num = "".join(num)
##    print num
    return num 

#returns all the index positions where the same number appears 
def findrepeats(decimals, ind):
##    print "Finding repeats of index %i..." %ind
    decimals = list(decimals)
    repeats = [ind]
    candidate = decimals.pop(ind) #no need to insert it back later because decimals won't be used anymore

    index = 1 #1 because 0 is the candidate
    for r in decimals:
        if candidate == r:
            repeats.append(index)
        index += 1
    if len(repeats)>1:
##        print repeats
        return repeats
    else:
##        print "No repetitions of", candidate
        return None

#breaks up the decimals into segments at the repeat positions of a number
def segment(deci, repeats, interval):
##    print "Segmenting..."
    deci = str(deci)
    repnum = list(deci)[repeats[0]] #any index of repeats would work
    tempsegments = deci.split(repnum)
    tempsegments.pop(0) #otherwise there will always be a blank element before the first segment

    segments = []
    for n in tempsegments:
        egment = list(n)
        egment.insert(0, repnum)
        segment = "".join(egment)
        segments.append(segment)
##    print segments

##    print "Applying interval..."
    intervalled = []
    index = 0
    while index<len(segments):
        intsegment = "".join(segments[index:index+interval])
        intervalled.append(intsegment)
        index += interval

##    print intervalled     
    return intervalled

def checkcycle(interval):
##    print "Checking if the intervals we found are repeats of a cycle..."
    is_cycle = True
    if len(interval)<3 and len(interval[0])<len(interval[1]):
        is_cycle = False
##        print "Not a cycle!"
        return is_cycle
    
    if len(interval)<3:
        cycle = list(interval[0])
        nextcycle = list(interval[1])

        if len(nextcycle)<10:
            is_cycle = False
##          print "Not enough decimals for this one, but doesn't look like it."
            return is_cycle
        
        index = 0
        accuracy = 0
        for digit in nextcycle:
            if digit == cycle[index]:
                accuracy += 1
                pass
            else:
                is_cycle = False
##                print "Not a cycle!"
                return is_cycle
            index += 1
            
    if len(interval)>2 and len(interval[0])<len(interval[1]) or len(interval)>2 and len(interval[1])<len(interval[2]):
        is_cycle = False
##        print "Not a cycle!"
        return is_cycle
    
    elif len(interval)>2:
        cycle = list(interval[0])
        nextcycle = list(interval[1])
        nextercycle = list(interval[2])

        index = 0
        if nextcycle == cycle:
            pass
        else:
            is_cycle = False
##            print "Not a cycle!"
            return is_cycle
        
        for digit in nextercycle:
            if digit == cycle[index]:
                pass
            else:
                is_cycle = False
##                print "Not a cycle!"
                return is_cycle
            index += 1
        
    if is_cycle == True:
##        print "It's a cycle!", interval[0]
        return is_cycle



### Start here! ###

cycles = []
longcycles = ["0"]
longest = 0
for d in range(2, 1001):
    getcontext().prec = 1000
    num = str(Decimal(1.0)/Decimal(d))
    print "\n1.0/" + str(d) #+ " = " + str(num)

    deci = getdecimals(num)
    is_cycle = False

    ind = 0
    for n in deci:
        if len(deci)-ind<longest: #save time
            break
        
        if is_cycle != True:
            repeats = None
            while repeats==None and ind<len(deci):
                repeats = findrepeats(deci, ind)
                ind += 1

            interval = 1
            while repeats!=None and is_cycle==False and interval<len(repeats):
                intervalled = segment(deci, repeats, interval)
                is_cycle = checkcycle(intervalled)
                interval += 1
            ind += 1
        else:
            print "Mission complete!"
            break
    
    if is_cycle:
        newcycle = str(intervalled[0])
        cycles.append(newcycle)
        if len(newcycle)>longest:
            longest = len(newcycle)
            name = str(newcycle), "d = %i" %d
            longcycles.append(name)
    else:
        print "Oh well."

print "Longest cycle is...", longcycles[-1]
