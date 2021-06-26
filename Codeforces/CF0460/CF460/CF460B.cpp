#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int digSum(ll n)
{
    int x=0;
    while (n)
    {
        x+=(n%10);
        n/=10;
    }
    return x;
}

ll binpow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll a,b,c,k;
    cin>>a>>b>>c;
    vector<int> v;
    for (ll i=1;i<82;++i)
    {
        k=b*binpow(i,a)+c;
        if (k>0&&k<=1000000000)
        {
            if (digSum(k)==i)
            {
                v.push_back(k);                
            }
        }
    }
    sort(v.begin(), v.end());
    cout<<sz(v)<<"\n";
    for (int i=0;i<sz(v);++i)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}