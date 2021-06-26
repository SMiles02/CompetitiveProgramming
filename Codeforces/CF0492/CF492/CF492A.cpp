#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin>>n;
	for (int i=1;i<500;++i)
	{
		k=(i*(i+1))/2;
		if (n==k)
		{
			cout<<i;
			return 0;
		}
		else if (k>n)
		{
			cout<<i-1;
			return 0;
		}
		n-=k;
	}
	return 0;
}