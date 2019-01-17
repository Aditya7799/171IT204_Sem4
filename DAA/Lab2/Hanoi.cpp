#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n;
long int counter;





void solve_hanoi(int n,char S,char I,char T)
{
	if(n>=1)
	{
		solve_hanoi(n-1,S,T,I);
		//cout<<"Move Disk"<< n <<"from" << S <<"to"<< T <<endl;
		counter++;
		solve_hanoi(n-1,I,S,T);
	}
	
}

int main(){
	// cout<<"Read N"<<endl;
	// cin>>n;
	// solve_hanoi(n,'S','I','T');

	for(int i=1;i<=100;i=i*10)
	{
		counter =0;
		solve_hanoi(i,'S','I','T');
		cout<<i<<" "<<counter<<endl;

	}

}

