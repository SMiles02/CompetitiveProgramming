#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,minX,minY,maxX,maxY,k,curX,curY,wCount,aCount,sCount,dCount;
	ll ans1,ans2;
	string s;
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>s;
		k=s.length();
		minX=0;maxX=0;minY=0;maxY=0;curX=0;curY=0;wCount=0;sCount=0;dCount=0;aCount=0;
		for (int i=0;i<k;++i)
		{
			if (s[i]=='W')
			{
				if (curY>minY)
				{
					wCount=1;
					//cout<<"w worked!\n";
				}
				++curY;
				if (curY>maxY)
				{
					sCount=0;
				}
				maxY=max(maxY,curY);
				
			}
			else if (s[i]=='A')
			{
				if (curX<maxX)
				{
					aCount=1;
					//cout<<"a worked!\n";
				}
				--curX;
				if (curX<minX)
				{
					dCount=0;
				}
				minX=min(minX,curX);
				
			}
			else if (s[i]=='S')
			{
				if (curY<maxY)
				{
					sCount=1;
					//cout<<"s worked!\n";
				}
				--curY;
				if (curY<minY)
				{
					wCount=0;
				}
				minY=min(minY,curY);
				
			}
			else
			{
				if (curX>minX)
				{
					dCount=1;
					//cout<<"d worked!\n";
				}
				++curX;
				if (curX>maxX)
				{
					aCount=0;
				}
				maxX=max(maxX,curX);
				
			}
			//cout<<"---TURN "<<i<<" maxX: "<<maxX<<", maxY: "<<maxY<<", minX: "<<minX<<", minY: "<<minY<<"\n";
		}
		//cout<<"maxX: "<<maxX<<", maxY: "<<maxY<<", minX: "<<minX<<", minY: "<<minY<<", right/left deduction: "<<max(aCount,dCount)<<", up/down deduction: "<<max(wCount,sCount)<<"\n";
		ans1=(maxX-minX+1);
		ans1*=(maxY-minY+1);
		ans2=ans1;
		if (wCount+sCount>0)
		{
			ans1=(maxY-minY);
			ans1*=(maxX-minX+1);
		}
		if (aCount+dCount>0)
		{
			ans2=(maxX-minX);
			ans2*=(maxY-minY+1);
		}
		cout<<min(ans1,ans2)<<"\n";
	}
	return 0;
}