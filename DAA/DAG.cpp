#include <bits/stdc++.h>
using namespace std;


void addedge(vector<int> adj[],int u,int v,int count[])
{
	adj[u].push_back(v);
	count[v]++;
}

void topological_sort(int V,vector<int> adj[],int count[])
{
	vector<int> S;
	for(int i =0;i<V;i++)
	{
		if(count[i]==0)
			S.push_back(i);
	}

	while(S.size()!=0)
	{
		int u =S.back();
		S.pop_back();
		if(S.size()==0)
			cout<<endl;
		cout<<u<<",";
		for(int j=0;j<adj[u].size();j++)
		{
			count[adj[u][j]]-=1;
			if(count[adj[u][j]]==0)
				S.push_back(adj[u][j]);
		}
	}
}


int main(){
	//cout<<"Enter total number of courses"<<endl;
	int V,E,u,v;
	cin>>V;
	vector<int> adj[V];
	int count_in_edges[V]={0};//number of incident edges on the Vertex v
	//cout<<"Enter the number of EDGES"<<endl;
	cin>>E;

	for(int i=1;i<=E;i++)
	{
		//cout<<"Enter u v"<<endl;
		cin>>u;
		cin>>v;
		addedge(adj,u,v,count_in_edges);
	}


	topological_sort(V,adj,count_in_edges);

return 0;
}


// vector<vector<int> > v;