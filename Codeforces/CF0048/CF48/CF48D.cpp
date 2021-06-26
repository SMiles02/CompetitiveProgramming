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
	int n,maxi;
	cin>>n;
	int a[n];
	int b[n];
	maxi=0;
	map<int,int> occurences;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		++occurences[a[i]];
		b[i]=occurences[a[i]];
		maxi=max(maxi,a[i]);
	}
	bool isTrue=true;
	for (int i=2;i<=maxi;++i)
	{
		if (occurences[i-1]<occurences[i])
		{
			isTrue=false;
			break;
		}
	}
	if (isTrue)
	{
		cout<<occurences[1]<<"\n";
		for (int i=0;i<n;++i)
		{
			cout<<b[i]<<" ";
		}
	}
	else
	{
		cout<<-1;
	}
	return 0;
}