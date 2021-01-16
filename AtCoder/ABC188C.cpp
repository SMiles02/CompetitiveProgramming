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
    int n,c=0,d=0,e=0,f=0;
    cin>>n;
    int a[(1<<(n-1))],b[(1<<(n-1))];
    for (int i=0;i<(1<<(n-1));++i)
        cin>>a[i];
    for (int i=0;i<(1<<(n-1));++i)
        cin>>b[i];
    for (int i=0;i<(1<<(n-1));++i)
        if (a[i]>c)
        {
            c=a[i];
            d=i;
        }
    for (int i=0;i<(1<<(n-1));++i)
        if (b[i]>e)
        {
            e=b[i];
            f=i;
        }
    if (c<e)
        cout<<d+1;
    else
        cout<<f+1+(1<<(n-1));
    return 0;
}