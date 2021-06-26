#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,a,b,c,d,e,ans,k;
	vector<string> s;
	string t;
	cin>>n>>m;
	for (int i=0;i<n;++i)
	{
		cin>>t;
		s.push_back(t);
	}
	ans=0;
	for (int i=0;i<m;++i)
	{
		cin>>k;
		a=0;
		b=0;
		c=0;
		d=0;
		e=0;
		for (int j=0;j<n;++j)
		{
			if (s[j][i]=='A')
			{
				++a;
			}
			else if (s[j][i]=='B')
			{
				++b;
			}
			else if (s[j][i]=='C')
			{
				++c;
			}
			else if (s[j][i]=='D')
			{
				++d;
			}
			else
			{
				++e;
			}
		}
		ans+=k*max({a,b,c,d,e});
	}
	cout<<ans;
	return 0;
}