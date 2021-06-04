#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll delivery(int n, int k, int l, int p[])
{
	ll ans=1e18, L[n+3], R[n+3];
	L[0]=0;R[n+1]=0;R[n+2]=0;
	for (int i=0;i<n;++i)
		L[i+1]=L[max(0,i+1-k)]+p[i]*2;
	for (int i=n-1;i>=0;--i)
	{
		R[i+1]=R[min(n+1,i+1+k)]+(l-p[i])*2;
		ans=min(ans,L[i]+R[i+1]);
	}
	ans=min(ans,L[n]);
	for (int i=0;i+k<=n;++i)
		ans=min(ans,L[i]+R[i+k+1]+l);
    return ans;
}

// int main()
// {
// 	int n,k,l;
// 	cin>>n>>k>>l;
// 	int p[n];
// 	for (int i=0;i<n;++i)
// 		cin>>p[i];
// 	cout<<delivery(n,k,l,p);
// }