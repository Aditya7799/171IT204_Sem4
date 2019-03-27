class node:
	def __init__(self,name):
		self.p=name
		self.al=[0]*3
		self.max=[0]*3
		self.done=False

		self.need=[0]*3

class SafeSequence:
	def __init__(self,n):
		self.n=n
		self.S=[]
		self.p=[0]*n
		self.ava=[0]*3
		self.i=0

	def getdata(self):
		for i in range(self.n):
			print("Enter the process name followed by its allocation and Maximum of x,y,z of process ",i+1 )
			na=input()
			self.p[i]=node(na)
			k=input().split()
			self.p[i].al[0],self.p[i].al[1],self.p[i].al[2]=int(k[0]),int(k[1]),int(k[2])
			l=input().split()
			self.p[i].max[0],self.p[i].max[1],self.p[i].max[2]=int(l[0]),int(l[1]),int(l[2])
			self.p[i].need[0],self.p[i].need[1],self.p[i].need[2]=self.p[i].max[0]-self.p[i].al[0],self.p[i].max[1]-self.p[i].al[1],self.p[i].max[2]-self.p[i].al[2]
		print("Enter the available value")
		m=input().split()
		self.ava[0],self.ava[1],self.ava[2]=int(m[0]),int(m[1]),int(m[2])

	def findseq(self):
		while(True):
			if self.countn()==0:
				break;
			print(self.i)
			if (self.comparev(self.i)):
				k=self.p[self.i]
				self.ava[0]+=k.al[0]
				self.ava[1]+=k.al[1]
				self.ava[2]+=k.al[2]
				k.done=True
				self.S.append(k.p)
			self.i+=1
			if self.i>=self.n:
				self.i=0




	def comparev(self,i):
		k=self.p[i].need
		l=self.ava
		if(k[0]<=l[0] and k[1]<=l[1] and k[2]<=l[2]):
			return True
		return False


	def countn(self):
		count=0
		for i in range(self.n):
			if self.p[i].done==False:
				count+=1
		print("count = ",count)
		return count

def main():
	n=int(input("Enter the number of processes : "))
	SS=SafeSequence(n)
	SS.getdata()

	SS.findseq()
	print("The required safe sequence  : \n")
	for i in range(n):
		print(SS.S[i],end=", ")
	print("\n")

main()
