#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,a,b,ans;
	cin>>n>>m>>a>>b;
	if (a*(n%m)>=b)
	{
		ans=b;
		n-=(n%m);
		ans+=(n/m)*b;
	}
	else
	{
		ans=a*(n%m);
		n-=(n%m);
		if (a*m>=b)
		{
			ans+=b*(n/m);
		}
		else
		{
			ans+=a*n;
		}
	}
	cout<<ans;
	return 0;
}