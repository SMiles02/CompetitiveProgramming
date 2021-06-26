#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,sum,ans;
	cin>>n;
	int a[n];
	sum=0;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	ans=0;
	for (int i=1;i<=n;++i)
	{
		ans+=a[n-i];
		if (ans*2>sum)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}