#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll ans;
	int n,lastDone;
	string s;
	cin>>s;
	n=s.length();
	ans=0;
	lastDone=-1;
	for (int i=0;i<n-3;++i)
	{
		if (s[i]=='b'&&s[i+1]=='e'&&s[i+2]=='a'&&s[i+3]=='r')
		{
			if (lastDone==-1)
			{
				ans+=((i+1)*(n-i-3));
				lastDone=i+1;
			}
			else
			{
				ans+=((i+1-lastDone)*(n-i-3));
				lastDone=i+1;
			}
			//cout<<"ans "<<ans<<"\n";
		}
	}
	cout<<ans;
	return 0;
}