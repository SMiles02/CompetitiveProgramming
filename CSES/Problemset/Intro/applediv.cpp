#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,k,applesDone=0;
ll a=0,b=0,ans=20000000000;
vector<int> v;

void combosMaker()
{
	if (applesDone==n)
	{
		ans=min(ans,abs(a-b));
	}
	else
	{
		++applesDone;
		a+=v[applesDone-1];
		combosMaker();
		a-=v[applesDone-1];
		b+=v[applesDone-1];
		combosMaker();
		b-=v[applesDone-1];
		--applesDone;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>k;
		v.push_back(k);
	}
	combosMaker();
	cout<<ans;
	return 0;
}