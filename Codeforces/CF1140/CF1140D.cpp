#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	ll ans;
	cin>>n;
	ans=0;
	for (int i=2;i<n;++i)
	{
		ans+=(i*(i+1));
	}
	cout<<ans;
	return 0;
}