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
    int n;
    cin>>n;
    int a[n+2],b[n+2],c[n+2],pre[n+2],suff[n+2];
    a[0]=a[n+1]=b[0]=b[n+1]=c[0]=c[n+1]=pre[0]=suff[n+1]=pre[n+1]=suff[0]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        c[i]=b[i]=a[i];
    }
    for (int i=1;i<=n;++i)
    {
        if (pre[i-1]==-1||b[i]<0)
        {
            pre[i]=-1;
            continue;
        }
        pre[i]=b[i];
        b[i+1]-=b[i];
    }
    for (int i=n;i;--i)
    {
        if (suff[i+1]==-1||c[i]<0)
        {
            suff[i]=-1;
            continue;
        }
        suff[i]=c[i];
        c[i-1]-=c[i];
    }
    /**
    for (int i=0;i<n+2;++i)
        cout<<pre[i]<<" ";
    cout<<"\n";
    for (int i=0;i<n+2;++i)
        cout<<suff[i]<<" ";
    cout<<"\n";
    **/
    if (pre[n]==0)
    {
        cout<<"YES\n";
        return;
    }
    for (int i=1;i<n;++i)
        if (pre[i-1]>=0&&suff[i+2]>=0&&a[i+1]>=pre[i-1]&&a[i]>=suff[i+2]&&a[i+1]-pre[i-1]==a[i]-suff[i+2])
        {
            cout<<"YES\n";
            return;
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