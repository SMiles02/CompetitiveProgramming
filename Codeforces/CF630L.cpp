#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	ll n=0,k;
	cin>>s;
	n=(s[0]-'0')*10000;
	n+=(s[2]-'0')*1000;
	n+=(s[4]-'0')*100;
	n+=(s[3]-'0')*10;
	n+=(s[1]-'0');
	k=n*n;
	k%=100000;
	k*=n;
	k%=100000;
	k*=n;
	k%=100000;
	k*=n;
	k%=100000;
	if (k<10)
	{
		cout<<"0000";
	}
	else if (k<100)
	{
		cout<<"000";
	}
	else if (k<1000)
	{
		cout<<"00";
	}
	else if (k<10000)
	{
		cout<<"0";
	}

	cout<<k;
	return 0;
}