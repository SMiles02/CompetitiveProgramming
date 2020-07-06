#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	int a[n];
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	if (n%2==0)
	{
		cout<<a[(n-2)/2];
	}
	else
	{
		cout<<a[(n-1)/2];
	}
	return 0;
}