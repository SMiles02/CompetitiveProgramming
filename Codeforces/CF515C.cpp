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
	int n;
	string s,ans;
	cin>>n;
	cin>>s;
	ans="";
	for (int i=0;i<n;++i)
	{
		if (s[i]=='2')
		{
			ans+="2";
		}
		if (s[i]=='3')
		{
			ans+="3";
		}
		if (s[i]=='4')
		{
			ans+="322";
		}
		if (s[i]=='5')
		{
			ans+="5";
		}
		if (s[i]=='6')
		{
			ans+="53";
		}
		if (s[i]=='7')
		{
			ans+="7";
		}
		if (s[i]=='8')
		{
			ans+="7222";
		}
		if (s[i]=='9')
		{
			ans+="7332";
		}
	}
	sort(ans.rbegin(),ans.rend());
	cout<<ans;
	return 0;
}