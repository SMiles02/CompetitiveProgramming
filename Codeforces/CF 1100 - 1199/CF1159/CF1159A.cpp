#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,cur,mini;
	string s;
	cin>>n;
	cin>>s;
	cur=0;
	mini=0;
	for (int i=0;i<n;++i)
	{
		if (s[i]=='+')
		{
			++cur;
		}
		else
		{
			--cur;
			mini=min(mini,cur);
		}
	}
	cout<<max(0,cur-min(mini,0));
	return 0;
}