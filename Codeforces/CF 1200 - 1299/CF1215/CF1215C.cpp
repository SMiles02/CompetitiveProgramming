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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string s,t;
	cin>>n;
	cin>>s;
	cin>>t;
	vector<int> aInS;
	vector<int> bInS;
	for (int i=0;i<n;++i)
	{
		if (s[i]!=t[i])
		{
			if (s[i]=='a')
			{
				aInS.push_back(i+1);
			}
			else
			{
				bInS.push_back(i+1);
			}
		}
	}
	if ((sz(aInS)+sz(bInS))%2)
	{
		cout<<-1;
	}
	else
	{
		if ((sz(aInS)%2)+(sz(bInS)%2)==0)
		{
			cout<<(sz(aInS)+sz(bInS))/2<<"\n";
			while (sz(aInS)>0)
			{
				cout<<aInS.back()<<" ";
				aInS.pop_back();
				cout<<aInS.back()<<"\n";
				aInS.pop_back();
			}
			while (sz(bInS)>0)
			{
				cout<<bInS.back()<<" ";
				bInS.pop_back();
				cout<<bInS.back()<<"\n";
				bInS.pop_back();
			}
		}
		else if ((sz(aInS)%2)+(sz(bInS)%2)==2)
		{
			cout<<(sz(aInS)/2)+(sz(bInS)/2)+2<<"\n";
			cout<<aInS.back()<<" "<<aInS.back()<<"\n";
			bInS.push_back(aInS.back());
			aInS.pop_back();
			while (sz(aInS)>0)
			{
				cout<<aInS.back()<<" ";
				aInS.pop_back();
				cout<<aInS.back()<<"\n";
				aInS.pop_back();
			}
			while (sz(bInS)>0)
			{
				cout<<bInS.back()<<" ";
				bInS.pop_back();
				cout<<bInS.back()<<"\n";
				bInS.pop_back();
			}
		}
	}
	return 0;
}