#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
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

void solve()
{
    int n,mx=0,l,r,mn;
    cin>>n;
    map<int,vector<int>> m;
    int pre[n+2],suf[n+2],a[n+2];
    pre[0]=suf[n+1]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        pre[i]=max(pre[i-1],a[i]);
        m[a[i]].push_back(i);
        mx=max(mx,a[i]);
    }
    for (int i=n;i;--i)
        suf[i]=max(suf[i+1],a[i]);
    if (sz(m[mx])>2)
    {
        cout<<"YES\n";
        cout<<m[mx][1]-1<<" 1 "<<n-m[mx][1]<<"\n";
        return;
    }
    l=m[mx][0];r=m[mx].back();
    mn=mx;
    for (int i=l;i<=r;++i)
        mn=min(mn,a[i]);
    while (1<l&&r<n)
    {
        if (pre[l-1]==mn&&suf[r+1]==mn)
        {
            cout<<"YES\n"<<l-1<<" "<<r-l+1<<" "<<n-r<<"\n";
            return;
        }
        if (min(min(pre[l-2],a[l-1]),min(mn,suf[r+1]))>=min(min(pre[l-1],mn),min(a[r+1],suf[r+2])))
            mn=min(mn,a[--l]);
        else
            mn=min(mn,a[++r]);
    }
    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}