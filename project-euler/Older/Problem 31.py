
def totalup():
    total = 0
    for d in denominations:
        total += d*freq[d]
    return total

#the sample denominations
denominations = [1, 2, 5, 10, 20, 50, 100, 200]

#populate freq
freq = {}
for d in denominations:
    freq.update( {d:0} )

#populate fmax
fmax = {}
for d in denominations:
    fmax.update( { d : 200/d } )


ways = []
notdone = True
while notdone:
    total = totalup()
    if total == 200:
        print "Got one:", freq
        ways.append(freq)

    freq[200] += 1

    if freq[200] > fmax[200]:
        freq[200] = 0
        freq[100] += 1

    if freq[100] > fmax[100]:
        freq[100] = 0
        freq[50] += 1

    if freq[50] > fmax[50]:
        freq[50] = 0
        freq[20] += 1

    if freq[20] > fmax[20]:
        freq[20] = 0
        freq[10] += 1

    if freq[10] > fmax[10]:
        freq[10] = 0
        freq[5] += 1

    if freq[5] > fmax[5]:
        freq[5] = 0
        freq[2] += 1

    if freq[2] > fmax[2]:
        freq[2] = 0
        freq[1] += 1

    if freq[1] > fmax[1]:
        notdone = False

print "Finished. :') "
