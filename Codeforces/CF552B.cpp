#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,k=9;
	cin>>n;
	if (n<10)
	{
		cout<<n;
		return 0;
	}
	else if (n<100)
	{
		cout<<(n-9)*2+k;
		return 0;
	}
	else if (n<1000)
	{
		cout<<(n-99)*3+(k*10*2)+k;
		return 0;
	}
	else if (n<10000)
	{
		cout<<(n-999)*4+(900*3)+(90*2)+9;
		return 0;
	}
	else if (n<100000)
	{
		cout<<(n-9999)*5+(k*10*10*10*4)+(k*10*10*3)+(k*10*2)+k;
		return 0;
	}
	else if (n<1000000)
	{
		cout<<(n-99999)*6+(k*10*10*10*10*5)+(k*10*10*10*4)+(k*10*10*3)+(k*10*2)+k;
		return 0;
	}
	else if (n<10000000)
	{
		cout<<(n-999999)*7+(k*100000*6)+(k*10000*5)+(k*1000*4)+(k*100*3)+(k*10*2)+9;
		return 0;
	}
	else if (n<100000000)
	{
		cout<<(n-9999999)*8+(9000000*7)+(900000*6)+(90000*5)+(9000*4)+(900*3)+(90*2)+9;
		return 0;
	}
	else if (n<1000000000)
	{
		cout<<(n-99999999)*9+(90000000*8)+(9000000*7)+(900000*6)+(90000*5)+(9000*4)+(900*3)+(90*2)+9;
		return 0;
	}
	else 
	{
		cout<<(n-999999999)*10+(k*100000000*9)+(90000000*8)+(9000000*7)+(900000*6)+(90000*5)+(9000*4)+(900*3)+(90*2)+9;
	}
	return 0;
}