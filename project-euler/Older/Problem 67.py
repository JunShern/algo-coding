

def getNumbers(string):
    #splits the whole string into a list of each line
    strlines = string.split("\n")

    #splits each line into a list of numbers
    lines = []
    for l in strlines:
        lines.append(l.split(" "))
        
    #convert all into integers
    rows = [] 
    for l in lines:
        new = []
        for n in l:
            new.append(int(n))
        rows.append(new)
        
    return rows

def assignIndex(row):
    ind = 0
    indexOf = {}
    for r in row:
        indexOf[r] = ind
        ind += 1
    return indexOf

def producePositionList(rows):
    posOf = []
    for row in rows:
        posOf.append( assignIndex(row) )
    return posOf

def sortNumbers(rows):
    for r in rows:
        rInd = rows.index(r)
        rows[rInd].sort()
        rows[rInd] = list(reversed(r))
    return rows

def findNext(newRows, rowNum, baseInd):
    row = newRows[rowNum]
    for n in row:
        ind = posOf[rowNum][n]
        if (ind == baseInd) or (ind == baseInd + 1) : # stop at the first(largest) adjacent numbers
            baseInd = posOf[rowNum][n]
            answers.append(n)
            break
        else: 
            continue
            
    return baseInd
        
string = """3
7 4
2 4 9
8 5 9 3"""

rows = getNumbers(string)
posOf = producePositionList(rows) # get the index of any number by calling indexOf[rowNum][numValue]
newRows = sortNumbers(rows)
print newRows

answers = [ newRows[0][0] ]
baseInd = 0
for row in newRows[1:] :
    print row
    rowNum = newRows.index(row)
    baseInd = findNext(newRows, rowNum, baseInd)
    
print "\n", answers, "\n", sum(answers)

