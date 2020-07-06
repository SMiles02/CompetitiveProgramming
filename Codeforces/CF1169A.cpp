#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,a,b,x,y;
	cin>>n>>a>>x>>b>>y;
	while (true)
	{
		if (a==n)
		{
			a=1;
		}	
		else
		{
			++a;
		}
		if (b==1)
		{
			b=n;
		}
		else
		{
			--b;
		}
		if (a==b)
		{
			cout<<"Yes";
			return 0;
		}
		if (a==x||b==y)
		{
			cout<<"No";
			return 0;
		}
	}
	return 0;
}