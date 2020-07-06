#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,r,b,r1,b1;
	string s;
	cin>>n;
	cin>>s;
	r=0;b=0;r1=0;b1=0;
	for (int i=0;i<n;++i)
	{
		if (s[i]=='r')
		{
			if (i%2)
			{
				++r1;
			}
			else
			{
				++r;
			}
		}
		else
		{
			if (i%2)
			{
				++b;
			}
			else
			{
				++b1;
			}
		}
	}
	//cout<<r1<<" "<<b1<<" "<<r<<" "<<" "<<b<<"\n";
	cout<<min(max(r,b),max(r1,b1));
	return 0;
}