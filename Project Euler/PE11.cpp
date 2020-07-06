#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ans;
	ans=0;
	int a[20][20];
	for (int i=0;i<20;++i)
	{
		for (int j=0;j<20;++j)
		{
			cin>>a[i][j];
		}
	}
	for (int i=0;i<17;++i)
	{
		for (int j=0;j<20;++j)
		{
			ans=max(ans,a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j]);
		}
	}
	for (int i=0;i<20;++i)
	{
		for (int j=0;j<17;++j)
		{
			ans=max(ans,a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3]);
		}
	}
	for (int i=0;i<17;++i)
	{
		for (int j=0;j<17;++j)
		{
			ans=max(ans,a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3]);
		}
	}
	for (int i=3;i<20;++i)
	{
		for (int j=0;j<17;++j)
		{
			ans=max(ans,a[i][j]*a[i-1][j+1]*a[i-2][j+2]*a[i-3][j+3]);
		}
	}
	cout<<ans;
	return 0;
}