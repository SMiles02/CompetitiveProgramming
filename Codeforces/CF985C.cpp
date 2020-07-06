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
    int n,k,d,l,r,m,c=0;
    ll ans=0;
    vector<int> v;
    cin>>n>>k>>d;
    int a[n*k];
    for (int i=0;i<n*k;++i)
        cin>>a[i];
    sort(a,a+(n*k));
    l=0;r=n*k-1;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (a[0]+d>=a[m])
            l=m;
        else
            r=m-1;
    }
    if (l+1<n)
    {
        cout<<0;
        return 0;
    }
    for (int i=l;i>=0;--i)
        v.push_back(a[i]);
    for (int i=0;i<n;++i)
    {
        ++c;
        ans+=v.back();
        v.pop_back();
        for (int j=1;j<k&&c+sz(v)>n;++j)
            v.pop_back();
    }
    cout<<ans;
    return 0;
}