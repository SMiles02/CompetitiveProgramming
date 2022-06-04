#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,h,k;
	ll ans;
	cin>>n>>h>>k;
	int a[n];
	cin>>a[0];
	ans=0;
	for (int i=1;i<n;++i)
	{
		cin>>a[i];
		ans+=((a[i-1]-(a[i-1]%k))/k);
		a[i-1]%=k;
		if (a[i-1]+a[i]>h)
		{
			a[i-1]=0;
			++ans;
		}
		else
		{
			a[i]+=a[i-1];
			a[i-1]=0;
		}
	}
	ans+=((a[n-1]-(a[n-1]%k))/k);
	a[n-1]%=k;
	if (a[n-1]>0)
	{
		++ans;
	}
	cout<<ans;
	return 0;
}