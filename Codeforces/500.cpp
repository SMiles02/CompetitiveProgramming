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
    ll n,l,mini,maxi,hasAscent,k,ans=0;
    cin>>n;
    vector<pair<ll,pair<ll,ll>>> v;
    map<ll,ll> maxiMap;
    map<ll,ll> ascensions;
    for (int i=0;i<n;++i)
    {
        cin>>l;
        cin>>mini;
        maxi=mini;
        hasAscent=0;
        for (int j=1;j<l;++j)
        {
            cin>>k;
            if (k>mini)
            {
                hasAscent=1;
            }
            mini=min(k,mini);
            maxi=max(k,maxi);
        }
        v.push_back({hasAscent,{mini,maxi}});
        ++maxiMap[maxi];
        if (hasAscent)
            ++ascensions[maxi];
    }
    for (int i=999999;i>=0;--i)
        maxiMap[i]+=maxiMap[i+1];
    for (int i=1;i<=1000000;++i)
        ascensions[i]+=ascensions[i-1];
    for (int i=0;i<n;++i)
    {
        if (v[i].first)
            ans+=n;
        else
            ans+=maxiMap[v[i].second.first+1]+ascensions[v[i].second.first];
    }
    cout<<ans;
    return 0;
}