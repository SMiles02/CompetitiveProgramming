#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin>>n;
	n*=(n-1);
	n/=2;
	cout<<n;
	return 0;
}