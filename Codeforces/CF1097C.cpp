#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,a,b,ans,k;
	string s;
	cin>>n;
	ans=0;
	map<int,int> pairs;
	for (int i=-500000;i<500001;++i)
	{
		pairs[i]=0;
	}
	for (int i=0;i<n;++i)
	{
		cin>>s;
		k=s.length();
		a=0;b=0;
		for (int j=0;j<k;++j)
		{
			if (s[j]=='(')
			{
				++a;
			}
			else
			{
				if (a>0)
				{
					--a;
				}
				else
				{
					++b;
				}
			}
		}
		if (a==0&&b!=0)
		{
			if (pairs[-b]==0)
			{
				++pairs[b];
			}
			else
			{
				++ans;
				--pairs[-b];
			}
		}
		else if (a!=0&&b==0)
		{
			if (pairs[a]==0)
			{
				++pairs[-a];
			}
			else
			{
				++ans;
				--pairs[a];
			}
		}
		else if (a==0&&b==0)
		{
			if (pairs[0]==0)
			{
				++pairs[0];
			}
			else
			{
				++ans;
				--pairs[0];
			}
		}
	}
	cout<<ans;
	return 0;
}