#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	ll cur=1;
	cin>>n;
	while (n--)
	{
		cur*=2;
		cur%=1000000007;
	}
	cout<<cur;
	return 0;
}