#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k,x,ans;
	double b;
	cin>>n>>k;
	map<int,int> mods;
	b=k;
	b/=2;
	//cout<<"b: "<<b<<"\n";
	for (int i=0;i<k;++i)
	{
		mods[i]=0;
	}
	while (n--)
	{
		cin>>x;
		++mods[x%k];
	}
	ans=(mods[0]/2);
	for (int i=1;i<b;++i)
	{
		ans+=min(mods[i],mods[k-i]);
		//cout<<"i: "<<i<<" - "<<mods[i]<<", k-i: "<<k-i<<" - "<<mods[k-i]<<"\n";
	}
	//cout<<"\n";
	if (k%2==0)
	{
		ans+=(mods[k/2]/2);
	}
	cout<<ans*2;
	return 0;
}