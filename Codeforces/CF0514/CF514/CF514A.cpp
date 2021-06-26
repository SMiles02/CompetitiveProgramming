#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin>>s;
	int zeroesDone=0;
	ll ans=0;
	for (int i=0;i<sz(s)-1;++i)
	{
		if ((s[i]-'0')>4&&(zeroesDone||s[i]!='9'))
		{
			ans*=10;
			ans+=9-(s[i]-'0');
			zeroesDone=1;
		}
		else
		{
			if (s[i]!='0')
			{
				zeroesDone=1;
			}
			ans*=10;
			ans+=(s[i]-'0');
		}
	}
	ans*=10;
	if ((!zeroesDone)&&s[sz(s)-1]=='9')
	{
		ans*=10;
		ans+=9;
	}
	else if ((s[sz(s)-1]-'0')<5)
	{
		ans+=(s[sz(s)-1]-'0');
	}
	else
	{
		ans+=9-(s[sz(s)-1]-'0');
	}
	cout<<ans;
	return 0;
}