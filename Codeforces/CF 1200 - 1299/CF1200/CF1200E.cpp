#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,cur,k,i;
	cin>>n;
	cur=0;
	string s,ans;
	cin>>s;
	k=s.length();
	
	for (int i=0;i<k;++i)
	{
		if (s[i]==' ')
		{

		}
	}
	return 0;
}