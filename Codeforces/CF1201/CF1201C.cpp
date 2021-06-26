#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	ll done;
	cin>>n>>k;
	int a[n];
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	done=1;
	if (n==1)
	{
		cout<<a[0]+k;
		return 0;
	}
	for (int i=((n-1)/2)+1;i<n;++i)
	{
		if (done*(a[i]-a[i-1]) > k)
		{
			cout<<a[i-1]+(k/done);
			return 0;
		}
		else
		{
			k-=done*(a[i]-a[i-1]);
			++done;
		}
	}
	cout<<a[n-1]+(k/done);
	return 0;
}