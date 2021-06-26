#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,q,l,r;
	cin>>n;
	int a[n+1];
	int prefixSum[n+1];
	a[0]=0;
	prefixSum[0]=0;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
		prefixSum[i]=a[i]+prefixSum[i-1];
	}
	cin>>q;
	for (int i=0;i<q;++i)
	{
		cin>>l>>r;
		cout<<((prefixSum[r]-prefixSum[l-1])/10)<<"\n";
	}
	return 0;
}