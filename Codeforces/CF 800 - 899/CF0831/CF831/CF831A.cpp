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
	int n,incr=0,equal=0,ans=1;
	cin>>n;
	int a[n];
	cin>>a[0];
	for (int i=1;i<n;++i)
	{
		cin>>a[i];
		if (a[i]>a[i-1])
		{
			if (incr)
			{
				ans=0;
			}
		}
		else if (a[i]==a[i-1])
		{
			incr=1;
			if (equal)
			{
				ans=0;
			}
		}
		else
		{
			incr=1;
			equal=1;
		}
	}
	if (ans)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}