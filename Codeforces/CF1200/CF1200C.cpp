#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,m,sY,eY;
	int q,sX,eX;
	cin>>n>>m>>q;
	for (int i=0;i<q;++i)
	{
		cin>>sX>>sY>>eX>>eY;
		if (sX==1&&eX==1)
		{
			
		}
	}
	return 0;
}