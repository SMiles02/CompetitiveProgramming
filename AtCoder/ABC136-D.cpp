#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,currentRightOdd,currentRightEven,lastTrap;
	string s;
	cin>>s;
	n=s.length();
	currentRightEven=0;
	currentRightOdd=0;
	lastTrap=1;
	int ans[n]={0};
	for (int i=0;i<n-1;++i)
	{
		if (s[i]=='R')
		{
			if (s[i+1]=='L')
			{
				if (i%2==0)
				{
					ans[i]+=currentRightEven+1;
					ans[i+1]+=currentRightOdd+1;
				}
				else
				{
					ans[i]+=currentRightOdd+1;
					ans[i+1]+=currentRightEven+1;
				}
				lastTrap=i+1;
				currentRightOdd=0;
				currentRightEven=0;
				++i;
			}
			else
			{
				if (i%2==0)
				{
					currentRightEven+=1;
				}
				else
				{
					currentRightOdd+=1;
				}
			}
		}
		else
		{
			if ((i-lastTrap)%2==0)
			{
				++ans[lastTrap];
			}
			else
			{
				++ans[lastTrap-1];
			}
		}
	}
	if (s[n-2]!='R')
	{
		if (((n-1)-lastTrap)%2==0)
		{
			++ans[lastTrap];
		}
		else
		{
			++ans[lastTrap-1];
		}
	}
	for (int i=0;i<n;++i)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}