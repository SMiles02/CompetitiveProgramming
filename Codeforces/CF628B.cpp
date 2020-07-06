#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll ans=0;
	string s;
	cin>>s;
	if (s[0]=='4'||s[0]=='8'||s[0]=='0')
	{
		++ans;
	}
	for (int i=0;i<sz(s)-1;++i)
	{
		if (s[i+1]=='4'||s[i+1]=='8'||s[i+1]=='0')
		{
			++ans;
		}
		if (((s[i]-'0')*10+(s[i+1]-'0'))%4==0)
		{
			ans+=i+1;
		}
	}
	cout<<ans;
	return 0;
}