#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,ans,d;
	cin>>n>>m;
	ans=0;
	if (m%n==0)
	{
		d=m/n;
		while (d%2==0)
		{
			d/=2;
			++ans;
		}
		while (d%3==0)
		{
			d/=3;
			++ans;
		}
		if (d==1)
		{
			cout<<ans;
		}
		else
		{
			cout<<-1;
		}
	}
	else
	{
		cout<<-1;
	}
	return 0;
}