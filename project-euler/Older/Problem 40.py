#Problem 40
#An irrational decimal fraction is created by concatenating the positive integers:
#0.123456789101112131415161718192021...
#It can be seen that the 12th digit of the fractional part is 1.
#If d(n) represents the nth digit of the fractional part, find the value of the following expression.
# d(1) * d(10) * d(100) * d(1000) * d(10000) * d(100000) * d(1000000)

number = []
for n in range(1, 1000000):
    number.append(str(n))
string = "".join(number)

answer = int(string[0])*int(string[9])*int(string[99])*int(string[999])*int(string[9999])*int(string[99999])*int(string[999999])
print answer
