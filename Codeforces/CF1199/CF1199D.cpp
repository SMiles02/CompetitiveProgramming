#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,q,p,k,x,grant;
	cin>>n;
	int a[n];
	int lastPayoff[n]={0};
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	cin>>q;
	int queries[q+1];
	for (int i=1;i<=q;++i)
	{
		cin>>k;
		if (k==2)
		{
			cin>>grant;
			queries[i]=grant;
		}
		else
		{
			cin>>p>>x;
			a[p-1]=x;
			lastPayoff[p-1]=i;
			queries[i]=0;
		}
	}
	queries[0]=0;
	for (int i=q-1;i>-1;--i)
	{
		queries[i]=max(queries[i],queries[i+1]);
	}
	for (int i=0;i<n;++i)
	{
		cout<<max(a[i],queries[lastPayoff[i]])<<" ";
	}
	return 0;
}