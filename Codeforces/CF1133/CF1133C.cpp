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
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	ans=1;
	bool reached;
	for (int i=0;i<n;++i)
	{
		reached=false;
		for (int j=i+ans;j<n;++j)
		{
			if (a[j]-a[i]>5)
			{
				reached=true;
				cur=j-i;
				break;
			}
			if (j==n-1)
			{
				reached=true;
				cur=j-i+1;
			}
		}
		if (reached)
		{
		ans=max(ans,cur);
		}
	}
	cout<<ans;
	return 0;
}