#Problem 22
#Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
#For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938  53 = 49714.
#What is the total of all the name scores in the file?

data = open('names.txt','r') # open in read mode
string = data.read()
names = string.split('","') #separate each name into an element of names

#due to the nature of split(), the first " and last " are not removed from the first and last names
##print names[0], names[-1] #this illustrate the problem if necessary
first = list(names[0])
first.pop(0) #remove the first "
names.pop(0) #remove the old name at names[0] since that one still has "
names.insert(0, "".join(first))

#do the same for the last name with a " at the end
last = list(names[-1])
last.pop(-1)
names.pop(-1)
names.append("".join(last))

#sort by alphabet
names = sorted(names, key=str.lower)

#give each letter its numeric value
alphabet = list("abcdefghijklmnopqrstuvwxyz")
scores = []
for name in names:
    letters = list(name)
    value = 0
    for l in letters:
        for a in alphabet:
            if l.lower()==a:
                value += alphabet.index(a)+1
    position = names.index(name)+1
    score = value*position
##    print name, value, position, score
    scores.append(score)

print sum(scores)
