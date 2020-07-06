#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, oneCount,n;
	string s;
	cin>>t;
	for (int i=0;i<t;++i)
	{
		cin>>s;
		oneCount=0;
		n=s.length();
		for (int j=0;j<n;++j)
		{
			if (s[j]=='1')
			{
				++oneCount;
			}
		}
		if (oneCount%2==0)
		{
			cout<<"LOSE\n";
		}
		else
		{
			cout<<"WIN\n";
		}
	}
	return 0;
}