#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string s;
	cin>>s;
	n=s.length();
	for (int i=0;i<n-2;++i)
	{
		if (s[i]==s[i+1])
		{
			if (s[i]!='a'&&s[i+2]!='a')
			{
				s[i+1]='a';
				//cout<<"test1";
			}
			else if (s[i]!='b'&&s[i+2]!='b')
			{
				s[i+1]='b';
				//cout<<"test2";
			}
			else
			{
				s[i+1]='c';
				//cout<<"test3";
			}
		}
	}
	if (n>1)
	{
		if (s[n-2]==s[n-1])
		{
			if (s[n-2]=='a')
			{
				s[n-1]='b';
			}
			else
			{
				s[n-1]='a';
			}
		}
	}
	cout<<s;
	return 0;
}