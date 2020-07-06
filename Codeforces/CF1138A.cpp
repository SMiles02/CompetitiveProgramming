#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}
 
string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,cur,k,ans;
	cin>>n;
	int t[n];
	cin>>t[0];
	vector<int> v;
	cur=1;
	for (int i=1;i<n;++i)
	{
		cin>>t[i];
		if (t[i]==t[i-1])
		{
			++cur;
		}
		else
		{
			v.push_back(cur);
			cur=1;
		}
	}
	v.push_back(cur);
	ans=0;
	k=v.size();
	for (int i=0;i<k-1;++i)
	{
		ans=max(ans,2*min(v[i],v[i+1]));
	}
	cout<<ans;
	return 0;
}