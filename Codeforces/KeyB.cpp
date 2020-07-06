#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
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
    int n,x,l,ans=0,c=-1e9;
    cin>>n;
    pair<int,int> v[n];
    for (int i=0;i<n;++i)
    {
        cin>>x>>l;
        v[i]={x+l,x-l};
    }
    sort(v,v+n);
    for (int i=0;i<n;++i)
    {
        if (v[i].second<c)
            continue;
        ++ans;
        c=v[i].first;
    }
    cout<<ans;
    return 0;
}