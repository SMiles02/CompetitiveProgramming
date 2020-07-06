#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	int a[n];
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	--a[0];
	bool isTrue = true;
	for (int i=1;i<n;++i)
	{
		if (a[i]<a[i-1])
		{
			isTrue=false;
			break;
		}
		if (a[i]>a[i-1])
		{
			--a[i];
		}
	}
	if (isTrue)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}