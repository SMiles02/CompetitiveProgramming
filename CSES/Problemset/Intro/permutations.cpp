#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	if (n==1)
	{
		cout<<1;
		return 0;
	}
	if (n<4)
	{
		cout<<"NO SOLUTION";
		return 0;
	}
	if (n==4)
	{
		cout<<"3 1 4 2";
		return 0;
	}
	for (int i=0;i*2+1<=n;++i)
	{
		cout<<2*i+1<<" ";
	}
	for (int i=0;i*2+2<=n;++i)
	{
		cout<<2*i+2<<" ";
	}
	return 0;
}