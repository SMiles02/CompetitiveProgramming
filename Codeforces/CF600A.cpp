#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).length()
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
	string s,a="",b="",cur="";
	cin>>s;
	int n=s.length(),allNums=1;
	map<char,int> numbers;
	numbers['0']=1;numbers['1']=1;numbers['2']=1;numbers['3']=1;numbers['4']=1;numbers['5']=1;numbers['6']=1;numbers['7']=1;numbers['8']=1;numbers['9']=1;
	map<char,int> isWeird;
	isWeird[';']=1;isWeird[',']=1;
	for (int i=0;i<n-1;++i)
	{
		if (isWeird[s[i]])
		{
			if (!allNums||!sz(cur))
			{
				b+=cur;
				b+=",";
				allNums=1;
			}
			else if (cur[0]=='0'&&sz(cur)>1)
			{
				b+=cur;
				b+=",";
			}
			else
			{
				a+=cur;
				a+=",";
			}
			cur="";
		}
		else
		{
			if (!numbers[s[i]])
			{
				allNums=0;
			}
			cur+=s[i];
		}
	}
	if (isWeird[s[n-1]])
	{
		if (!allNums||!sz(cur))
		{
			b+=cur;
			b+=",";
			allNums=1;
		}
		else if (cur[0]=='0'&&sz(cur)>1)
		{
			b+=cur;
			b+=",";
		}
		else
		{
			a+=cur;
			a+=",";
		}
		b+=",";
	}
	else
	{
		cur+=s[n-1];
		if (!numbers[s[n-1]])
		{
			allNums=0;
		}
		if (!allNums||!sz(cur))
		{
			b+=cur;
			b+=",";
			allNums=1;
		}
		else if (cur[0]=='0'&&sz(cur)>1)
		{
			b+=cur;
			b+=",";
		}
		else
		{
			a+=cur;
			a+=",";
		}
	}
	if (sz(a))
	{
		a.pop_back();
		cout<<quoted(a)<<"\n";
	}
	else
	{
		cout<<"-\n";
	}
	if (sz(b))
	{
		b.pop_back();
		cout<<quoted(b)<<"\n";
	}
	else
	{
		cout<<"-\n";
	}
	return 0;
}