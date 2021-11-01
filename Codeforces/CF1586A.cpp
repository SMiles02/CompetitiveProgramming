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

bool isPrime(int n)
{
    if (n==1)
        return 0;
    for (int i=2;i*i<=n;++i)
        if (n%i==0)
            return 0;
    return 1;
}

void solve()
{
    int n,s=0;
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        s+=a[i];
    if (!isPrime(s))
    {
        cout<<n<<"\n";
        for (int i=1;i<=n;++i)
            cout<<i<<" ";
        cout<<"\n";
        return;
    }
    for (int i=1;i<=n;++i)
        if (!isPrime(s-a[i]))
        {
            cout<<n-1<<"\n";
            for (int j=1;j<=n;++j)
                if (i!=j)
                    cout<<j<<" ";
            cout<<"\n";
            return;
        }
    for (int i=1;i<=n;++i)
        for (int j=i+1;j<=n;++j)
            if (!isPrime(s-a[i]-a[j]))
            {
                cout<<n-2<<"\n";
                for (int k=1;k<=n;++k)
                    if (i!=k&&j!=k)
                        cout<<k<<" ";
                cout<<"\n";
                return;
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