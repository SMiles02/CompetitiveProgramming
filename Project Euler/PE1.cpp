#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ans=0;
	int n;
	cin>>n;
	for (int i=1;i<n;++i)
	{
		if (i%3==0||i%5==0)
		{
			ans+=i;
		}
	}
	cout<<ans;
	return 0;
}