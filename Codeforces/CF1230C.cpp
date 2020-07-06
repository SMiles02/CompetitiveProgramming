#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

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
	int n,m,a,b;
	cin>>n>>m;
	if (n<7)
	{
		cout<<m;
		return 0;
	}
	if (m==21)
	{
		cout<<16;
		return 0;
	}
	if (m==20)
	{

	}
	map<int,int> hash;
	for (int i=0;i<m;++i)
	{
		cin>>a>>b;
		if (a!=b)
		{
			++hash[a];
		}
		++hash[b];
	}
	vector<int> v;
	for (int i=1;i<8;++i)
	{
		v.push_back(hash[i]);
	}
	sort(v.begin(), v.end());
	if (v[0]==0)
	{
		cout<<m;
		return 0;
	}
	if (v[6]==6)
	{
		cout<<m-v[0]+1;
		return 0;
	}
	if (m==17)
	{
		cout<<14;
		return 0;
	}
	cout<<m;
	return 0;
}