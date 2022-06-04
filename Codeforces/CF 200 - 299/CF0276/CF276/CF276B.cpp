#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,odds;
	string s,alpha;
	cin>>s;
	n=s.length();
	alpha="abcdefghijklmnopqrstuvwxyz";
	map<char,int> letters;
	for (int i=0;i<26;++i)
	{
		letters[alpha[i]]=0;
	}
	for (int i=0;i<n;++i)
	{
		++letters[s[i]];
	}
	odds=0;
	for (int i=0;i<26;++i)
	{
		if (letters[alpha[i]]%2==1)
		{
			++odds;
		}
	}
	if (odds<2||odds%2==1)
	{
		cout<<"First";
	}
	else
	{
		cout<<"Second";
	}
	return 0;
}