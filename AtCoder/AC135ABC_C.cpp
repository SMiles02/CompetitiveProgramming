#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	int a[n+1];
	int b[n];
	ll ans;
	for (int i=0;i<n+1;++i)
	{
		cin>>a[i];
	}
	for (int i=0;i<n;++i)
	{
		cin>>b[i];
	}
	ans=0;
	for (int i=0;i<n;++i)
	{
		ans+=min(a[i],b[i]);
		b[i]=max(0,b[i]-a[i]);
		//cout<<"i: "<<i<<" - "<<ans<<"\n";
		ans+=min(a[i+1],b[i]);
		a[i+1]=max(a[i+1]-b[i],0);
		//cout<<"i: "<<i<<" - "<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}