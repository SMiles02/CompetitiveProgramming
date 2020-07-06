#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,x,y,ans;
	string s;
	cin>>n>>x>>y;
	cin>>s;
	ans=0;
	for (int i=1;i<=y;++i)
	{
		if (s[n-i] == '1')
		{
			++ans;
		}
	}
	if (s[n-(y+1)]=='0')
	{
		++ans;
	}
	for (int i=y+2;i<=x;++i)
	{
		if (s[n-i] == '1')
		{
			++ans;
		}
	}
	cout<<ans;
	return 0;
}