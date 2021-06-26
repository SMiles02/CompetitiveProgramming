#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	double I;
	cin>>n>>I;
	I*=8;
	I/=n;
	k=floor(I);
	int a[n];
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int dp[n];
	dp[0]=1;
	for (int i=1;i<n;++i)
	{
		if (a[i]==a[i-1])
		{
			dp[i]=dp[i-1];
		}
		else
		{
			dp[i]=dp[i-1]+1;
		}
	}
	int cur=dp[n-1];
	if (cur<=k)
	{
		
	}
	return 0;
}