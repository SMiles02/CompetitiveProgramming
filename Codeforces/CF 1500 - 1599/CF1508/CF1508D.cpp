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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x=10,m,ans=0;
    //int n=0;
    m=(1<<x);
    for (int i=0;i<m;++i)
        for (int j=i+1;j<m;++j)
            for (int k=j+1;k<m;++k)
            {
                //++n;
                ans=max(ans,min({__builtin_popcount(i^j),__builtin_popcount(i^k),__builtin_popcount(j^k)}));
            }
    cout<<ans<<"\n";
    // cout<<n<<"\n";
    // for (int i=0;i<m;++i)
    //     for (int j=i+1;j<m;++j)
    //         for (int k=j+1;k<m;++k)
    //         {
    //             cout<<x/2<<"\n";
    //             for (int l=0;l<x;++l)
    //                 cout<<min((1<<l)&i,1);
    //             cout<<"\n";
    //             for (int l=0;l<x;++l)
    //                 cout<<min((1<<l)&j,1);
    //             cout<<"\n";
    //             for (int l=0;l<x;++l)
    //                 cout<<min((1<<l)&k,1);
    //             cout<<"\n";
    //         }
    return 0;
}