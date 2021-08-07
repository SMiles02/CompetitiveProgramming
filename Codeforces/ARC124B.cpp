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

const int N = 3e3;
int n, a[N], b[N];

bool check(int x)
{
    map<int,int> m;
    for (int i=0;i<n;++i)
        ++m[b[i]];
    for (int i=0;i<n;++i)
        if (--m[a[i]^x]<0)
            return 0;
    return 1;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        cin>>b[i];
    set<int> s;
    vector<int> ans;
    for (int i=0;i<n;++i)
        s.insert(a[0]^b[i]);
    for (int i : s)
        if (check(i))
            ans.push_back(i);
    cout<<sz(ans)<<"\n";
    for (int i : ans)
        cout<<i<<"\n";
    return 0;
}