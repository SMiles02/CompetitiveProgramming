//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
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
    int n,s=0;
    cin>>n;
    int a[n],b[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    if (n&1)
    {
        for (int i=0;i+3<n;i+=2)
            cout<<a[i+1]<<" "<<-a[i]<<" ";
        bool ok=0;
        for (int i=n-3;i<n;++i)
            for (int j=n-3;j<n;++j)
                if (i!=j)
                    for (int k=n-3;k<n;++k)
                        if (i!=k&&j!=k&&a[i]!=-a[j]&&ok==0)
                        {
                            ok=1;
                            b[i]=a[k];
                            b[j]=a[k];
                            b[k]=-(a[i]+a[j]);
                        }
        cout<<b[n-3]<<" "<<b[n-2]<<" "<<b[n-1]<<"\n";
    }
    else
    {
        for (int i=0;i<n;i+=2)
            cout<<a[i+1]<<" "<<-a[i]<<" ";
        cout<<"\n";
    }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}