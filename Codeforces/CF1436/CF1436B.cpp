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
    for (int i=2;i*i<=n;++i)
        if (n%i==0)
            return 0;
    return 1;
}

void solve()
{
    int n,k;
    cin>>n;
    int a[n][n];
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            a[i][j]=4;
    for (int i=3;i;i+=2)
        if ((!isPrime(i))&&isPrime(4*(n-1)+i))
        {
            k=i;
            break;
        }
    for (int i=0;i<n;++i)
        a[i][i]=k;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
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