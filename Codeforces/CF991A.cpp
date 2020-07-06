#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a,b,c,n;
	cin>>a>>b>>c>>n;
	if (a+b-c<n&&a>=c&&b>=c)
	{
		cout<<n-a-b+c;
	}
	else
	{
		cout<<-1;
	}
	return 0;
}