
text = """319
680
180
690
129
620
762
689
762
318
368
710
720
710
629
168
160
689
716
731
736
729
316
729
729
710
769
290
719
680
318
389
162
289
162
718
729
319
790
680
890
362
319
760
316
729
380
319
728
716"""

def findDigits(data):
    ans = []
    for d in data:
        d = list(str(d))
        d = map(int,d)
        for n in d:
            if n not in ans:
                ans.append(n)
    return ans

def getData(text):
    text = map(int,text.split("\n"))
    data = []
    for n in text:
        if n not in data:
            data.append(n)
    return data

def evaluate(cand):
    ans = [cand]
    for d in data:
        d = map(int, list(str(d)))
        if cand not in d:
            continue
        for n in d[d.index(cand):]:
            if n not in ans:
                ans.append(n)
        for n in d[:d.index(cand)]:
            if n not in ans:
                ans.insert(0,n)
    return ans
            
data = getData(text)
digits = findDigits(data)
evals = {cand: evaluate(cand) for cand in digits}
ans = []    
while len(evals[3])>0:
    for cand in evals:
        if len(evals[3])<=0:
            break
        if cand==evals[cand][-1]:
            print "%i is the last value in" %(cand), evals[cand]
            ans.insert(0,cand)
            for other in evals:
                evals[other].remove(cand)
print int("".join(map(str,ans)))
