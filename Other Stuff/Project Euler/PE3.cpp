#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, ans;
	cin>>n;
	ans=1;
	for (ll i=2;i*i<=n;++i)
	{
		if (n%i==0)
		{
			ans=i;
			while (n%i==0)
			{
				n/=i;
			}
		}
	}
	cout<<max(n,ans);
	return 0;
}