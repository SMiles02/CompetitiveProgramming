#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,differences=0;
	cin>>n;
	int a[n];
	int b[n];
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	for (int i=0;i<n;++i)
	{
		if (a[i]!=b[i])
		{
			++differences;
		}
	}
	if (differences<3)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}