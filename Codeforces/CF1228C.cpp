#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define MOD 1000000007
using namespace std;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2)%MOD;
    res*=res;
    res%=MOD;
    if (b % 2)
        return (res * a)%MOD;
    else
        return (res)%MOD;
}

vector<ll> primeFactorisation(int k)
{
	vector<ll> v;
	for (ll i=2;i*i<=k;++i)
	{
		if (!(k%i))
		{
			v.push_back(i);
			while (!(k%i))
			{
				k/=i;
			}
		}
	}
	if (k>1)
	{
		v.push_back(k);
	}
	return v;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x,k;
	ll n,cur,ans=1;
	cin>>x>>n;
	vector<ll> v = primeFactorisation(x);
	k=v.size();
	for (int i=0;i<k;++i)
	{
		cur=(n/v[i]);
		while (cur)
		{
			ans*=binpow(v[i],cur);
			ans%=MOD;
			cur/=v[i];
		}
	}
	cout<<ans;
	return 0;
}