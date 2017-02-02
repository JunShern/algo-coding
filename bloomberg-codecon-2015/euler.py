#Problem 42
#The nth term of the sequence of triangle numbers is given by, tn = (1/2)*n*(n+1); so the first ten triangle numbers are:
#1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
#By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
#Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?


import time

def createtnums(limit):
    n = 1
    tnum = 0
    tnums = []
    while tnum < limit:
        tnum = (n*(n+1))/2
        tnums.append(tnum)
        n += 1
    return tnums

def numerize(word):
    translate = dict(zip( ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"] , list(range(1,27)) ))
    letters = list(word)

    values = []
    for l in letters:
        values.append(translate[l])
    return sum(values)

def check(word, tnums):
    value = numerize(word)
    is_tword = value in tnums
    return is_tword

def getwords(filename):
    data = open(filename,'r') # open in read mode
    string = data.read()
    words = string.split('","') #separate each name into an element of names

    first = list(words[0])
    words.pop(0)
    first.pop(0)
    first = "".join(first)
    words.insert(0,first)

    last = list(words[-1])
    words.pop(-1)
    last.pop(-1)
    last = "".join(last)
    words.append(last)

    return words

tStart = time.time()
tnums = createtnums(200)
words = getwords("words.txt")

count = 0
for word in words:
    is_tword = check(word, tnums)
    if is_tword:
        count += 1
print count

print "Runtime = " + str(time.time() - tStart)
