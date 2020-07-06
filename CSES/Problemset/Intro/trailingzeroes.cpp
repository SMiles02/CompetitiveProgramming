#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,cur=5,ans=0;
	cin>>n;
	while (cur<=n)
	{
		ans+=(n/cur);
		cur*=5;
	}
	cout<<ans;
	return 0;
}