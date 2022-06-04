#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,x,y;
	cin>>n>>x>>y;
	int a[n+1];
	a[0]=1000000001;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	bool isTrue;
	for (int i=1;i<=n;++i)
	{
		isTrue=true;
		for (int j=max(1,i-x);j<i;++j)
		{
			if (a[j]<=a[i])
			{
				isTrue=false;
				break;
			}
		}
		for (int j=i+1;j<=min(i+y,n);++j)
		{
			if (a[j]<=a[i])
			{
				isTrue=false;
				break;
			}
		}
		if (isTrue)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}