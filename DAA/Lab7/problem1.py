def maximalsubset(l):
	l=sorted(l,key=lambda x:x[1])
	subset=[]
	for i in l:
		if(len(subset)==0):
			subset.append(i)
		elif(subset[-1][1]<=i[0]):
			subset.append(i)

	return subset



def main():
	l=[(1,3),(2,8),(2,5),(3,7),(4,8),(4,6),(6,12),(7,10)]
	a=maximalsubset(l)
	print(a)

main()