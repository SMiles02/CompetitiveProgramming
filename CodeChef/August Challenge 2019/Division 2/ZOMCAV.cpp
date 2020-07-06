#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}
string sorting(int n, int caves[], int zombies[])
{
	for (int i=0;i<n;++i)
	{
		if (caves[i]!=zombies[i])
		{
			return "NO\n";
		}
	}
	return "YES\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t,n,k;
	cin>>t;
	for (int i=0;i<t;++i)
	{
		cin>>n;
		int c[n];
		int c2[n];
		int h[n];
		for (int j=0;j<n;++j)
		{
			cin>>c[j];
			c2[j]=0;
		}
		for (int j=0;j<n;++j)
		{
			cin>>h[j];
		}
		for (int j=0;j<n;++j)
		{
			k=c[j];
			for (int m=max(j-k,0);m<=min(n-1,j+k);++m)
			{
				++c2[m];
			}
		}
		sort(c2,c2+n);
		sort(h,h+n);
		/**for (int j=0;j<n;++j)
		{
			cout<<c2[j]<<" ";
		}
		cout<<"\n";**/
		cout<<sorting(n,c2,h);
	}
	return 0;
}