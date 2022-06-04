#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	ll ans,cur;
	cin>>n;
	ll a[n];
	ll b[n];
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		a[i]*=(n-i);
		a[i]*=(i+1);
		//cout<<"a[i] "<<a[i]<<"\n";
	}
	sort(a,a+n);
	ans=0;
	for (int i=0;i<n;++i)
	{
		cin>>b[i];
	}
	sort(b,b+n,greater<int>());
	for (int i=0;i<n;++i)
	{
		cur=a[i];
		cur%=MOD;
		cur*=b[i];
		cur%=MOD;
		ans+=cur;
		ans%=MOD;
	}
	cout<<ans;
	return 0;
}