#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,ans,cur;
	cin>>n;
	int a[n];
	cin>>a[0];
	cur=1;
	ans=1;
	for (int i=1;i<n;++i)
	{
		cin>>a[i];
		if (a[i]<=2*a[i-1])
		{
			++cur;
		}
		else
		{
			ans=max(cur,ans);
			cur=1;
		}
	}
	ans=max(cur,ans);
	cout<<ans;
	return 0;
}