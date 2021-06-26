#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,m,k,sum=0;
	double ans=0,cur;
	cin>>n>>m>>k;
	int a[n];
	for (ll i=0;i<n;++i)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	for (ll i=0;i<min(k+1,n);++i)
	{
		cur=sum;
		cur+=min(k-i,m*(n-i));
		cur/=(n-i);
		ans=max(cur,ans);
		sum-=a[i];
	}
	cout<<setprecision(10)<<ans;
	return 0;
}