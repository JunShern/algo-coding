
def nextNum(num):
	num = map(int, list(str(num)))
	nextN = 0
	for n in num:
		nextN += n**2
	return nextN

def loopToEnd(num, path1, path89):
	path = []
	
	while (num!=1) and (num!=89) :
		#if num < 100 :
		#	path.append(num)	
		if num in path1:
			num = 1
		elif num in path89:
			num = 89
		else :
			num = nextNum(num)

	if (num==1) :
		##path1 += path
		return 1
	elif (num==89) :
		##path89 += path
		return 89
	
	else :
		print "Something is wrong!"
	
	return -1

def main() :
	path1 = []
	path89 = []

	count89 = 0
	for n in range(1,1000000) :
		end = loopToEnd(n, path1, path89)
		if (end==89) :
			if n < 1000:
				path89.append(n)
			count89 += 1
		elif end==1 and n < 1000 :
			path1.append(n)

	print "All done! The answer is %i! :)))" %(count89)

if __name__ == "__main__" :
	import profile	
	profile.run("main()")
