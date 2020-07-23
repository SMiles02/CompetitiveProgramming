#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
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

int ans[10001],t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=1;i<10001;++i)
        for (int j=1;i*i+j*j+i*j<10001;++j)
        {
            t=i*i+j*j+i*j;
            for (int k=1;t+k*k+i*k+j*k<10001;++k)
                ++ans[t+k*k+i*k+j*k];
        }
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<"\n";
    return 0;
}