#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,ans;
	cin>>n;
	ans=0;
	for (int i=1;i<=min(9,n);++i)
	{
		++ans;
		//cout<<i<<" ";
	}
	for (int i=100;i<=min(999,n);++i)
	{
		++ans;
		//cout<<i<<" ";
	}
	for (int i=10000;i<=min(99999,n);++i)
	{
		++ans;
		//cout<<i<<" ";
	}
	cout<<ans;
	return 0;
}