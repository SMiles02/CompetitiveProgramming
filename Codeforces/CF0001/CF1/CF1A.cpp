#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
	if (a>b)
	{
		return a;
	}
	return b;
}

ll min(ll a, ll b)
{
	if (a>b)
	{
		return b;
	}
	return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m,a;
    cin>>n>>m>>a;
    cout<<max(n/a+min(1,n%a),1)*max(m/a+min(1,m%a),1);
    return 0;
}