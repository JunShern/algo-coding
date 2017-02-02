#Problem 39
#If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
#{20,48,52}, {24,45,51}, {30,40,50}
#For which value of p  1000, is the number of solutions maximised?

def find_ab(c):
    for b in range( c*2/3 , c ):
        for a in range(1,b):
            if c**2 == a**2 + b**2:
                solution = [a,b,c]
                return solution
    return None

def find_solutions(peri):
    solutions = []
    for c in range( peri/3 , peri-(peri/2) ):
        solution = find_ab(c)
        if solution == None:
            continue
        if sum(solution) == peri:
            solutions.append(solution)

    if len(solutions)==0:
        return None

    else:
        print str(peri), solutions
        return solutions

longest = []
for p in range(500,1000):
    solutions = find_solutions(p)
    if solutions != None:
        print solutions
        if len(solutions)>len(longest):
            longest = solutions
print longest
