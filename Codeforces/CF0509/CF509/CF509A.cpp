#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	int a[n][n];
	a[0][0]=1;
	for (int i=0;i<n;++i)
	{
		a[i][0]=1;
		a[0][i]=1;
	}
	for (int i=1;i<n;++i)
	{
		for (int j=1;j<n;++j)
		{
			a[i][j]=a[i-1][j]+a[i][j-1];
		}
	}
	cout<<a[n-1][n-1];
	return 0;
}