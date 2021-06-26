#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	map<char,int> starters;
	string s,alpha;
	alpha="abcdefghijklmnopqrstuvwxyz";
	for (int i=0;i<26;++i)
	{
		starters[alpha[i]]=0;
	}
	int n,ans,a,b;
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>s;
		++starters[s[0]];
	}
	ans=0;
	for (int i=0;i<26;++i)
	{
		a=starters[alpha[i]];
		b=a/2;
		a-=b;
		//cout<<alpha[i]<<" "<<a<<" "<<b<<"\n";
		ans+=max(0,((a*a)-a)/2)+max(0,((b*b)-b)/2);
	}
	cout<<ans;
	return 0;
}