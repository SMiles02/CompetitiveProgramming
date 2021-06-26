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
	int n,k,maxi;
	ll ans=0,cur;
	cin>>n;
	int raise[n][2];
	maxi=0;
	for (int i=0;i<n;++i)
	{
		cin>>raise[i][0];
		cin>>raise[i][1];
		maxi=max(maxi,raise[i][1]);
		for (int j=1;j<raise[i][0];++j)
		{
			cin>>k;
			raise[i][1]=max(raise[i][1],k);
			maxi=max(maxi,k);
		}
	}
	for (int i=0;i<n;++i)
	{
		cur=maxi-raise[i][1];
		cur*=raise[i][0];
		ans+=cur;
	}
	cout<<ans;
	return 0;
}