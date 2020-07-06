#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,q;
	ll m,k;
	cin>>n>>q;
	int a[n];
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	int operation[n][2];
	for (int i=1;i<n;++i)
	{
		operation[i][0]=a[0];
		operation[i][1]=a[i];
		if (a[0]<a[i])
		{
			a[0]=a[i];
			a[i]=operation[i][0];
		}
	}
	for (int i=0;i<q;++i)
	{
		cin>>m;
		if (m<n)
		{
			cout<<operation[m][0]<<" "<<operation[m][1]<<"\n";
		}
		else
		{
			k=m%(n-1);
			if (k==0)
			{
				k=n-1;
			}
			cout<<a[0]<<" "<<min(operation[k][0],operation[k][1])<<"\n";
		}
	}
	return 0;
}