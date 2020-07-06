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
	int n,ones,twos,k;
	cin>>n;
	ones=0;twos=0;
	while (n--)
	{
		cin>>k;
		if (k==1)
		{
			++ones;
		}
		else
		{
			++twos;
		}
	}
	if (twos>0)
	{
		cout<<"2 ";
		--twos;
	}
	if (ones>0)
	{
		cout<<"1 ";
		--ones;
	}
	while (twos--)
	{
		cout<<"2 ";
	}
	while (ones--)
	{
		cout<<"1 ";
	}
	return 0;
}