#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin>>n;
	int odds=0,evens=0;
	while (n--)
	{
		cin>>k;
		if (k%2)
		{
			++evens;
		}
		else
		{
			++odds;
		}
	}
	cout<<min(odds,evens);
	return 0;
}