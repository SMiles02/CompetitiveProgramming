#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k,oneLocation;
	string x,y;
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>x;
		cin>>y;
		m=x.length();
		k=y.length();
		for (int i=1;i<=k;++i)
		{
			if (y[k-i]=='1')
			{
				oneLocation=i;
				break;
			}
		}
		for (int i=oneLocation;i<=m;++i)
		{
			if (x[m-i]=='1')
			{
				cout<<i-oneLocation<<"\n";
				break;
			}
		}
	}
	return 0;
}