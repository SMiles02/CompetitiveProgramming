#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,cur=1,maxi=1;
	string s;
	cin>>s;
	n=s.length();
	for (int i=1;i<n;++i)
	{
		if (s[i]==s[i-1])
		{
			++cur;
		}
		else
		{
			maxi=max(maxi,cur);
			cur=1;
		}
	}
	maxi=max(maxi,cur);
	cout<<maxi;
	return 0;
}