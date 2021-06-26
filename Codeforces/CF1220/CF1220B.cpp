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

int gcd(int a,int b)
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
	ll n,g,k,a;
	cin>>n;
	if (n==1)
	{
		cout<<5;
		return 0;
	}
	if (n==2)
	{
		cin>>k>>g;
		cin>>k>>g;
		cout<<k<<" 1";
		return 0;
	}
	ll table[n][n];
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<n;++j)
		{
			cin>>table[i][j];
		}
	}
	a=table[0][1]*table[0][2];
	//cout<<"Step 1: "<<a<<"\n";
	a/=table[1][2];
	//cout<<"Step 2: "<<a<<"\n";
	a=sqrt(a);
	//cout<<"Step 3: "<<a<<"\n";
	cout<<a;
	for (int i=1;i<n;++i)
	{
		cout<<" "<<table[0][i]/a;
	}
	return 0;
}