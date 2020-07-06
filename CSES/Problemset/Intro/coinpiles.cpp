#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,a,b;
	cin>>n;
	while (n--)
	{
		cin>>a>>b;
		if ((a+b)%3==0&&min(a,b)*2>=max(a,b))
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}