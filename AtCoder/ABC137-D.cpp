#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,a,b;
	ll ans=0;
	cin>>n>>m;
	map<int,int> maxMoneyEarned;
	for (int i=1;i<110001;++i)
	{
		maxMoneyEarned[i]=0;
	}
	for (int i=0;i<n;++i)
	{
		cin>>a>>b;
		if (a+b)
	}
	return 0;
}