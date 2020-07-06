#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	int b[n-1];
	for (int i=0;i<n-1;++i)
	{
		cin>>b[i];
	}
	sort(b,b+(n-1));
	for (int i=0;i<n-1;++i)
	{
		if (b[i]!=i+1)
		{
			cout<<i+1;
			return 0;
		}
	}
	cout<<n;
	return 0;
}