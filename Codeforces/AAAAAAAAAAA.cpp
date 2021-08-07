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

const int X = 6;
int n=6;
bitset<10> ans[10];

void solve(int k, vector<int> v)
{
    int ct=0;
    for (int i=0;i<n;++i)
        ct+=(v[i]!=i);
    ans[k][ct]=1;
    if (k==min((n+1)/2,X))
        return;
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
        {
            swap(v[i],v[j]);
            solve(k+1, v);
            swap(v[i],v[j]);
        }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    solve(0, v);
    for (int i=0;i<=min((n+1)/2,X);++i)
    {
        cout<<i<<": ";
        for (int j=0;j<=n;++j)
            if (ans[i][j])
                cout<<j<<" ";
        cout<<"\n";
    }
    return 0;
}