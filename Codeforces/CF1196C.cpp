#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q,n,x,y,maxX,maxY,minX,minY,f1,f2,f3,f4;
	cin>>q;
	for (int i=0;i<q;++i)
	{
		cin>>n;
		maxX=100000;maxY=100000;minX=-100000;minY=-100000;
		for (int j=0;j<n;++j)
		{
			cin>>x>>y>>f1>>f2>>f3>>f4;
			if (f1==0)
			{
				minX=max(minX,x);
			}
			if (f2==0)
			{
				maxY=min(maxY,y);
			}
			if (f3==0)
			{
				maxX=min(maxX,x);
			}
			if (f4==0)
			{
				minY=max(minY,y);
			}
		}
		if (maxX<minX||maxY<minY)
		{
			cout<<"0\n";
		}
		else
		{
			cout<<"1 "<<maxX<<" "<<maxY<<"\n";
		}
	}
	return 0;
}