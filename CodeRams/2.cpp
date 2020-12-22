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

const int INF=1e9;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,mi,ma,ans=0;
    cin>>n>>x;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        for (int j=i;j<n;++j)
        {
            mi=1e9;
            ma=0;
            for (int k=i;k<=j;++k)
            {
                mi=min(mi,a[k]);
                ma=max(ma,a[k]);
            }
            if (ma-mi==x)
                ++ans;
        }
    cout<<ans;
    return 0;
}