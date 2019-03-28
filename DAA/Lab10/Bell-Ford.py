class Graph:
	def __init__(self,n=None,e=None):
		self.nodes=n
		self.adL=[[] for _ in range(n)]

	def add_edge(self,source,destination):
		self.adL[destination]=source

	def Bell-Ford(self):
		x=[None for i in range(self.nodes)]
		T=[ x for i range(self.nodes)]

		for i in range(self.nodes):
			T[0][i]=0
			T[i][0]=99999

		for k in range(self.nodes-1):
			for u in self.adL[]






def main():
	G=Graph(4)
	
	G.add_edge(0,1)
	G.add_edge(0,2)
	G.add_edge(2,3)






main()
