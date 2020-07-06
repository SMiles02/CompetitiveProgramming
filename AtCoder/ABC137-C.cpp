#include <bits/stdc++.h>
#define ll long long
using namespace std;

string sortString(string &str) 
{ 
   sort(str.begin(), str.end()); 
   return str;
} 

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	ll ans,cur;
	cin>>n;
	string s;
	string a[n];
	for (int i=0;i<n;++i)
	{
		cin>>s;
		s=sortString(s);
		a[i]=s;
		//cout<<s<<"\n";
	}
	sort(a,a+n);
	cur=1;
	ans=0;
	for (int i=1;i<n;++i)
	{
		if (a[i-1]==a[i])
		{
			++cur;
		}
		else
		{
			cur*=(cur-1);
			cur/=2;
			ans+=cur;
			cur=1;
		}
	}
	cur*=(cur-1);
	cur/=2;
	ans+=cur;
	cur=1;
	cout<<ans;
	return 0;
}