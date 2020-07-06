#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}
 
string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s,cur,t;
	cin>>s;
	int n=s.length(),ans=1;
	vector<string> v;
	t=s[0];
	cur="";
	for (int i=1;i<n;++i)
	{
		//cout<<i<<", t: "<<t<<", cur: "<<cur<<"\n";
		cur+=s[i];
		if (cur==t)
		{
			if (i<n-1)
			{
				cur+=s[i+1];
				t=cur;
				cur="";
				++i;
				++ans;
			}
		}
		else
		{
			++ans;
			t=cur;
			cur="";
		}
	}
	cout<<ans;
	return 0;
}