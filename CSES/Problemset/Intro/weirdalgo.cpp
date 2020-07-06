#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long n;
	cin>>n;
	while (n>1)
	{
		cout<<n<<" ";
		if (n%2)
		{
			n*=3;
			++n;
		}
		else
		{
			n/=2;
		}
	}
	cout<<1;
	return 0;
}