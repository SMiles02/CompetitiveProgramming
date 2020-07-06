#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin>>n;
	set<int> s;
	while (n--)
	{
		cin>>k;
		if (k)
		{
			s.insert(k);
		}
	}
	cout<<s.size();
	return 0;
}