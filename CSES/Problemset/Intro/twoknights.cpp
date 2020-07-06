#include <bits/stdc++.h>
#define ll long long
#define sq(a) (a)*(a)
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin>>n;
	for (ll i=1;i<=n;++i)
	{
		cout<<(sq(i)*(sq(i)-1)/2)-(8*(i-2)*(i-1)/2)<<"\n";
	}
	return 0;
}