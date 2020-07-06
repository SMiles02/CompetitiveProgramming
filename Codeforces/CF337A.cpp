#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,ans;
	cin>>n>>m;
	int a[m];
	for (int i=0;i<m;++i)
	{
		cin>>a[i];
	}
	sort(a,a+m);
	ans=1000;
	for (int i=0;i<=m-n;++i)
	{
		ans=min(ans,a[i+n-1]-a[i]);
	}
	cout<<ans;
	return 0;
}