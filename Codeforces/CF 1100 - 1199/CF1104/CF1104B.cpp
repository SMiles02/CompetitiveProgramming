#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ans=0;
	string s;
	cin>>s;
	vector<char> v;
	v.push_back(s[0]);
	for (int i=1;i<sz(s);++i)
	{
		if (s[i]==v.back())
		{
			v.pop_back();
			++ans;
		}
		else
		{
			v.push_back(s[i]);
		}
	}
	if (ans%2)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}