# Problem 6
# The sum of the squares of the first ten natural numbers is,
#   1**2 + 2**2 + ... + 10**2 = 385
# The square of the sum of the first ten natural numbers is,
#   (1 + 2 + ... + 10)**2 = 552 = 3025
# Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
# Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

import math

squareofsum = sum(range(1, 101))**2

squares = []
for n in range(1, 101):
    squares.append(n**2)
sumofsquares = sum(squares)

diff = math.fabs(squareofsum - sumofsquares)
print diff
