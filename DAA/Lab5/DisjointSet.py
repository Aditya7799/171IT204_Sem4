class Node:
	def __init__(self,value,parent=None):
		self.value=value
		self.parent=parent
		self.rank=0

class DisjointSet:
	def __init__(self):
		self.Sets=[] #Stores Node of all the sets
		self.roots=[]

	def makeSet(self,x):
		temp=Node(x)
		temp.parent=temp
		self.Sets.append(temp)
		self.roots.append(temp)

		


	def findSet_UBR(self,i):
		if(i.parent==i):
			return i
		else:
			return(self.findSet_UBR(i.parent))

	def findSet_PC(self,x):
		if(x.parent==x):
			return x
		else:
			y=self.findSet_PC(i.parent)
			x.parent=y

	def union(self,x,y):
		Rx=self.findSet_PC(x)
		Ry=self.findSet_PC(y)

		if(Rx.rank>Ry.rank):
			Ry.parent=Rx
			self.roots.remove(Ry)
		elif(Rx.rank<Ry.rank):
			Rx.parent=Ry
			self.roots.remove(Rx)
		else:
			Ry.parent=Rx
			self.roots.remove(Ry)
			Rx.rank+=1

	def findnode(self,x):
		for i in self.Sets:
			if(i.value==x):
				return i

	



def main():
	S=DisjointSet()

	for i in range(0,5):
		S.makeSet(i)

	a=S.findnode(3)
	b=S.findnode(1)
	c=S.findnode(4)

	S.union(a,b)
	S.union(a,c)

	print(S.findSet_UBR(c).value)

main()

		

	