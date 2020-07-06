#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,a,b,last;
	cin>>n;
	bool isTrue=true;
	cin>>a>>b;
	last=max(a,b);
	for (int i=1;i<n;++i)
	{
		cin>>a>>b;
		if (max(a,b)<=last)
		{
			last=max(a,b);
		}
		else if (min(a,b)<=last)
		{
			last=min(a,b);
		}
		else
		{
			isTrue=false;
		}
	}
	if (isTrue)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}