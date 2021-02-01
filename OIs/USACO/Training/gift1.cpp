/*
ID: mahajan6
TASK: gift1
LANG: C++14                 
*/

#include <bits/stdc++.h>
#define ll long long
//#define fout cout
//#define fin cin
using namespace std;

int index(int abc, string array[], string name)
{
	for (int ind=0;ind<abc;++ind)
	{
		if (array[ind]==name)
		{
			return ind;
		}
	}
	return -1;;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int n,k,l,amount,people;
    fin>>n;
    string s,t;
    string names[n];
    int balances[n]={0};
    for (int i=0;i<n;++i)
    {
    	fin>>s;
    	names[i]=s;
    }
    for (int i=0;i<n;++i)
    {
    	fin>>s;
    	k=index(n,names,s);
    	fin>>amount>>people;
    	//cout<<k<<"\n";
    	if (people==0)
    	{
    		balances[k]+=amount;
    	}
    	else
    	{
    		balances[k]-=amount;
    		balances[k]+=amount%people;
    		amount-=(amount%people);
    		for (int j=0;j<people;++j)
    		{
    			fin>>t;
    			l=index(n,names,t);
    			balances[l]+=(amount/people);
    			//cout<<names[k]<<" gives "<< names[l]<<" "<<(amount/people)<<"\n";
    		}
    	}
    }
    for (int i=0;i<n;++i)
    {
    	fout << names[i] <<" " << balances[i] <<endl;
    }
	return 0;
}