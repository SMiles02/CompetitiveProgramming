#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(string numToFind, std::vector<string> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,cur,ans,j;
	string s;
	cin>>n;
	map<string,int> scores;
	vector<string> v;
	ans=0;
	for (int i=0;i<n;++i)
	{
		cin>>s>>cur;
		if (index(s,v)==-1)
		{
			scores[s]=cur;
			v.push_back(s);
		}
		else
		{
			scores[s]+=cur;
		}
	}
	j=v.size();
	for (int i=0;i<j;++i)
	{
		ans=max(ans,scores[v[i]]);
	}
	cout<<ans;
	return 0;
}