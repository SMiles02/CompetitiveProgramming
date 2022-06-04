#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k;
	cin>>n>>m;
	int a[n][m];
	int b[n][m];
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
		{
			cin>>a[i][j];
		}
	}
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
		{
			cin>>b[i][j];
			if (a[i][j]>b[i][j])
			{
				//cout<<"change"<<i<<" "<<j<<"\n";
				//cout<<a[i][j]<<"\n";
				//cout<<b[i][j]<<"\n";
				k=a[i][j];
				a[i][j]=b[i][j];
				b[i][j]=k;
			}
		}
	}
	bool isTrue;
	isTrue=true;
	for (int i=1;i<m;++i)
	{
		if (a[0][i]<=a[0][i-1])
		{
			isTrue=false;
		}
	}
	for (int i=1;i<n;++i)
	{
		if (a[i][0]<=a[i-1][0])
		{
			isTrue=false;
		}
	}
	for (int i=1;i<n;++i)
	{
		for (int j=1;j<m;++j)
		{
			if (a[i][j]<=a[i-1][j] || a[i][j]<=a[i][j-1])
			{
				isTrue=false;
			}
		}
	}
	for (int i=1;i<m;++i)
	{
		if (b[0][i]<=b[0][i-1])
		{
			isTrue=false;
		}
	}
	for (int i=1;i<n;++i)
	{
		if (b[i][0]<=b[i-1][0])
		{
			isTrue=false;
		}
	}
	for (int i=1;i<n;++i)
	{
		for (int j=1;j<m;++j)
		{
			if (b[i][j]<=b[i-1][j] || b[i][j]<=b[i][j-1])
			{
				isTrue=false;
			}
		}
	}
	if (isTrue)
	{
		cout<<"Possible";
	}
	else
	{
		cout<<"Impossible";
	}
	return 0;
}