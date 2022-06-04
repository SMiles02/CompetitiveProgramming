#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

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

vector<int> binMaker(ll n)
{
	vector<int> m(61);
	for (int i=60;i>=0;--i)
	{
		m[i]=(n%2);
		n/=2;
	}
	return m;
} 

int sharer(vector<int> a, vector<int> b)
{
	for (int i=0;i<61;++i)
	{
		if (b[i]>a[i])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	ll theScore=0;
	cin>>n;
	map<ll,int> amounts;
	vector<ll> individuals;
	map<ll,vector<int>> binaryRepresentation;
	map<ll,ll> scores;
	ll a[n];
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		if (!amounts[a[i]])
		{
			individuals.push_back(a[i]);
			binaryRepresentation[a[i]]=binMaker(a[i]);
		}
		++amounts[a[i]];
	}
	for (int i=0;i<n;++i)
	{
		cin>>k;
		scores[a[i]]+=k;
	}
	n=individuals.size();
	map<ll,int> done;
	vector<ll> added;
	for (int i=0;i<n;++i)
	{
		if (amounts[individuals[i]]>1)
		{
			added.push_back(individuals[i]);
			theScore+=scores[individuals[i]];
			done[individuals[i]]=1;
			//cout<<theScore<<"\n";
		}
	}
	k=added.size();
	for (int i=0;i<n;++i)
	{
		if (!done[individuals[i]])
		{
			for (int j=0;j<k;++j)
			{
				if (sharer(binaryRepresentation[added[j]],binaryRepresentation[individuals[i]]))
				{
					theScore+=scores[individuals[i]];
					break;
				}
			}
		}
	}
	cout<<theScore;
	return 0;
}