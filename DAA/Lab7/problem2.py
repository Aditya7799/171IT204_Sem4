def findminprocess(i):
	#takes O(nlogn)
	s=sorted(i)
	groups=[]
	#takes O(n^2)
	for x in s:
		flag=0
		for y in groups:
			if(y[-1][1]<=x[0]):
				y.append(x)
				flag=1
				break
		if(flag == 0):
			groups.append([x])

		
	return groups

def main():
	intervals=[(1,3),(1,6),(1,3),(4,6),(4,10),(8,12),(8,12),(11,15),(13,15),(13,15)]
	groups=findminprocess(intervals)
	print("Minimmum Number of Resources:",len(groups))
	for x,i in enumerate(groups):
		print("Resource ",x,"jobs:",i)



main()