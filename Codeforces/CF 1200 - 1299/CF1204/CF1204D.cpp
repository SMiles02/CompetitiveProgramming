#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string s,ans="0";
	cin>>s;
	n=s.length();
	for (int i=1;i<n;++i)
	{
		if (s[i]=='1')
		{
			ans+="0";
		}
		else if (s[i-1]=='0')
		{
			ans+="0";
		}
		else
		{
			ans.pop_back();
			ans+="10";
		}
	}
	cout<<ans;
	return 0;
}