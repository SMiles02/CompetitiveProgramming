#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,mini;
	cin>>n;
	int a[n];
	mini=0;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		if (a[i]>=0)
		{
			a[i]=-a[i]-1;
		}
		mini=min(mini,a[i]);
	}
	if (n%2==1)
	{
		for (int i=0;i<n;++i)
		{
			if (a[i]==mini)
			{
				a[i]=-a[i]-1;
				break;
			}
		}
	}
	for (int i=0;i<n;++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}