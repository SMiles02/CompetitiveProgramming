#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,h,m,maxi;
	ll ans;
	cin>>n>>h>>m;
	int a[m][3];
	for (int i=0;i<m;++i)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	ans=0;
	for (int i=1;i<=n;++i)
	{
		maxi=h;
		for (int j=0;j<m;++j)
		{
			if (a[j][0]<=i&&i<=a[j][1])
			{
				maxi=min(maxi,a[j][2]);
			}
		}
		ans+=(maxi*maxi);
	}
	cout<<ans;
	return 0;
}