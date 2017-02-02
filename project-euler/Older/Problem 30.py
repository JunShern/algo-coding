
def digits(num):
    digits = list(str(num))
    return digits

def sumfifthpowers(num):
    number = digits(num)
    powered = []
    for n in number:
        n = int(n)
        powered.append(n**5)
    return sum(powered)

answers = []
for n in range(1,1000000):
    if sumfifthpowers(n)==n and n!=1:
        answers.append(n)
        print n

print "The answer is... %i!" %sum(answers)
