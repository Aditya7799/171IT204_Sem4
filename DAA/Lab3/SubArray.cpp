#include<iostream>
#include<vector>


int main()
{	
	vector<int> A;
	A.push_back(-2);
	A.push_back(10);
	A.push_back(-4);
	A.push_back(12);
	A.push_back(-9);

	maxSumSubarray(A);

	return 0;
}


// void maxSumSubarray(vector<int> a,int low ,int high)
// {	
// 	for(int i=low;i<=high;i++)
// 	{
// 		maxSumSubarray(a,)
// 	}


// }


