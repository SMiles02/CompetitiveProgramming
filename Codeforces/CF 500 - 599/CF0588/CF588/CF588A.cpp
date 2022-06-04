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
	int p[n];
	for (int i=0;i<n;++i)
	{
		cin>>a[i]>>p[i];
	}
	ans=0;
	for (int i=0;i<n;++i)
	{
		cur=0;
		for (int j=i;j<n;++j)
		{
			if (j==n-1&&p[j]>=p[i])
			{
				cur+=a[j];
				ans+=(p[i]*cur);
				i=j;
				break;
			}
			if (p[j]<p[i])
			{
				ans+=(p[i]*cur);
				i=j-1;
				break;
			}
			cur+=a[j];
		}
	}
	cout<<ans;
	return 0;
}