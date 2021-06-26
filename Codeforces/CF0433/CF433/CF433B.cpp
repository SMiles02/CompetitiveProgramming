#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,type,l,r;
	cin>>n;
	int a[n+1];
	int b[n+1];
	a[0]=0;
	b[0]=0;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+(n+1));
	ll dp1[n+1];
	ll dp2[n+1];
	dp1[0]=0;
	dp2[0]=0;
	for (int i=1;i<=n;++i)
	{
		dp1[i]=dp1[i-1]+a[i];
		dp2[i]=dp2[i-1]+b[i];
	}
	cin>>m;
	for (int i=0;i<m;++i)
	{
		cin>>type>>l>>r;
		if (type==1)
		{
			cout<<dp1[r]-dp1[l-1]<<"\n";
		}
		else
		{
			cout<<dp2[r]-dp2[l-1]<<"\n";
		}
	}
	return 0;
}