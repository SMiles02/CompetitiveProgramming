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

const int INF = 1e9;
int ans[10000000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n=1e6,x,y=0;
    for (int i=0;i<=n;++i)
        ans[i]=INF;
    int c=0;
    for (int i=0;i*2020<=(n+5*2020);++i)
        for (int j=0;j*2021<=(n+5*2021);++j)
            ans[i*2020+j*2021]=min(ans[i*2020+j*2021],++c);
    for (int i=0;i<=n;++i)
        if (ans[i]^INF&&ans[i]>y)
        {
            y=ans[i];
            x=i;
        }
    cout<<x<<" "<<y<<"\n";
    return 0;
}