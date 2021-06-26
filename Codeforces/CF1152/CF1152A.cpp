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
	int n,m,k;
	cin>>n>>m;
	map<int,int> mods;
	mods[0]=0;mods[1]=0;mods[2]=0;mods[3]=0;
	while (n--)
	{
		cin>>k;
		++mods[k%2];
	}
	while (m--)
	{
		cin>>k;
		++mods[(k%2)+2];
	}
	cout<<min(mods[0],mods[3])+min(mods[1],mods[2]);
	return 0;
}