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
	sort(a,a+n);
	if (a[n-1]<a[n-2]+a[n-3])
	{
		cout<<"YES\n";
		for (int i=0;i<n-2;++i)
		{
			cout<<a[i]<<" ";
		}
		cout<<a[n-1]<<" "<<a[n-2];
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}