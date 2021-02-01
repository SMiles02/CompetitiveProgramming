#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	ll ans1,ans2;
	ans1=0;
	ans2=0;
	for (int i=1;i<=n;++i)
	{
		ans1+=(i*i);
		ans2+=i;
	}
	ans2*=ans2;
	cout<<ans2-ans1;
	return 0;
}