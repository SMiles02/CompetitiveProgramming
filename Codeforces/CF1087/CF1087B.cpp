#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k,nk,ans,cur;
	cin>>n>>k;
	nk=n*k;
	ans=nk+1;
	for (int i=2;i<k;++i)
	{
		if (n%i==0)
		{
			cur=nk/i;
			cur+=i;
			ans=min(cur,ans);
		}
	}
	cout<<ans;
	return 0;
}