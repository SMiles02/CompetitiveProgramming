#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,ans=0,h,mi;
	map<pair<int,int>,int> m;
	cin>>n;
	while (n--)
	{
		cin>>h>>mi;
		++m[make_pair(h,mi)];
		ans=max(ans,m[make_pair(h,mi)]);
	}
	cout<<ans;
	return 0;
}