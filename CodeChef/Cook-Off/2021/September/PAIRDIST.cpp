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
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    if (n==1)
        cout<<"YES\n69 69\n";
    else if (n==2)
        cout<<"YES\n0 0\n0 "<<a[0]+a[1]<<"\n";
    else if (n==3)
        cout<<"YES\n0 0\n0 "<<a[0]+a[1]<<"\n"<<a[2]<<" "<<a[0]<<"\n";
    else if (n==4)
        cout<<"YES\n0 0\n0 "<<a[0]+a[1]<<"\n"<<a[2]<<" "<<a[0]<<"\n"<<-a[3]<<" "<<a[0]<<"\n";
    else
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