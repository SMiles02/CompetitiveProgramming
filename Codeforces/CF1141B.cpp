#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,cur,ans;
	cin>>n;
	int a[n];
	ans=0;cur=0;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		if (a[i])
		{
			++cur;
		}
		else
		{
			ans=max(ans,cur);
			cur=0;
		}
	}
	for (int i=0;i<n;++i)
	{
		if (a[i])
		{
			++cur;
		}
		else
		{
			ans=max(ans,cur);
			cur=0;
		}
	}
	ans=max(ans,cur);
	cout<<ans;
	return 0;
}