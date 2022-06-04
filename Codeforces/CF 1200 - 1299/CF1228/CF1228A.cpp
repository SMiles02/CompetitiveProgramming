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

int digitsAreDifferent(int n)
{
	map<int,int> numbers;
	while (n)
	{
		if (numbers[n%10])
		{
			return 0;
		}
		++numbers[n%10];
		n/=10;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int l,r;
	cin>>l>>r;
	for (int x=l;x<=r;++x)
	{
		if (digitsAreDifferent(x))
		{
			cout<<x;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}