#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	if (n%2==0)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	vector<int> ans;
	for (int i=0;i<n;++i)
	{
		if (i%2==0)
		{
			cout<<(2*i+1)<<" ";
		}
		else
		{
			cout<<(2*i+2)<<" ";
		}
	}
	for (int i=0;i<n;++i)
	{
		if (i%2==0)
		{
			cout<<(2*i+2)<<" ";
		}
		else
		{
			cout<<(2*i+1)<<" ";
		}
	}
	return 0;
}