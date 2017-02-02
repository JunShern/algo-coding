
def power(a,b):
    return a**b

answers = []
for a in range(2,101):
    print a
    for b in range(2,101):
        ans = power(a,b)
        if ans not in answers:
            answers.append(ans)

print len(answers)
