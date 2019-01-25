#include<iostream>
#include<vector>
#include <bits/stdc++.h> 
using namespace std;

int count_split(vector<int> a,int low,int mid,int high)
{	int count=0;
	vector<int> L(a.begin()+low, a.begin()+mid+1);
	vector<int> R(a.begin()+mid+1, a.begin()+high+1);
	sort(L.begin(), L.end()); 
	sort(R.begin(), R.end());
	int l=0,r=0;
	while(l<L.size() && r<R.size())
	{
		if(L[l]<R[r])
			l++;
		if(L[l]>R[r])
		{
			r++;
			count=count+(L.size()-1-l)+1;
		}
	}

	return count;
}

int count_inversions(vector<int> a,int low,int high)
{
	if(low>=high)
		return 0;
	else
	{
		int mid=(low +high)/2;
		return(count_inversions(a,low,mid)+count_inversions(a,mid+1,high)+count_split(a,low,mid,high));
	}
}

int main()
{
	vector<int> a;
	a.push_back(0);
	a.push_back(2);
	a.push_back(8);
	a.push_back(1);
	a.push_back(6);
	cout<<count_inversions(a,0,4)<<" Inversions"<<endl;
	return 0;
}


