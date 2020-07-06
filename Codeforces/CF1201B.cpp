#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	ll sum;
	cin>>n;
	int a[n];
	sum=0;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];	
	}
	sort(a,a+n);
	for (int i=0;i<n-1;++i)
	{
		sum+=a[i];
	}
	if (sum<a[n-1])
	{
		cout<<"NO";
		return 0;
	}
	sum+=a[n-1];
	if (sum%2==0)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}