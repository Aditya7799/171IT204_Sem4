import heapq as H

class Node:
	def __init__(self,freq=0,value=None,left=None,right=None):
		self.freq=freq
		self.value=value
		self.left=left
		self.right=right

	def __lt__(self,b):
		return(self.freq<b.freq)

	def __str__(self):
		return(self.value)



def Huffman(l):
	leaves=[]
	for a,b in l.items():
		temp=Node(b,a)
		leaves.append(temp)

	H.heapify(leaves)

	for i in range(1,len(l)):
		T1=H.heappop(leaves)
		T2=H.heappop(leaves)
		node=Node(T1.freq+T2.freq,T1.value+T2.value,T1,T2)
		H.heappush(leaves,node)

	return leaves[0]



def main(l):
	root=Huffman(l)
	codes={}
	size=0
	#finding encodings of symbols
	for a,b in l.items():
		code=""
		curr=root
		while(curr.left!= None):
			if(a in curr.left.value):
				code=code+"0"
				curr=curr.left
			elif(a in curr.right.value):
				code=code+"1"
				curr=curr.right

		# print("Encoding of",a,"is",code)
		codes[a]=code
		size=size+len(code)*curr.freq


	print("Final Size of the compressed file is",size)
	return codes




def readfile():
	dir={}
	f=open('textfile.txt')
	o=open('encoded.bin','wb')
	x=f.readline()
	while(len(x)!=0):
		for i in x:
			if(i in dir):
				dir[str(i)]=int(dir[str(i)])+1
			else:
				dir[str(i)]=1
		x=f.readline()
	f.close()
	codes=main(dir)
	f=open('textfile.txt')
	x=f.readline()
	while(len(x)!=0):
		for i in x:
			o.write(int(codes[i]).to_bytes(len(codes[i]),"big"))
		x=f.readline()


readfile()

