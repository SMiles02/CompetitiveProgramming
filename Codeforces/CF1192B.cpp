#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,q,w,l1,l2;
	ll last,d,c;
	cin>>n>>q>>w;
	edges[n-1][3];
	for (int i=0;i<n-1;++i)
	{
		cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
	}
	last=0;
	for (int i=0;i<q;++i)
	{
		cin>>d>>c;
		d=(d+last)%(n-1);
		c=(c+last)%w;
		edges[d][2]=c;
		
	}
	return 0;
}