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
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<char,char> m1,m2;
    string alpha="abcdefghijklmnopqrstuvwxyz", x;
    cin>>x;
    for (int i=0;i<26;++i)
    {
        m2[alpha[i]]=x[i];
        m1[x[i]]=alpha[i];
    }
    int n;
    string s;
    cin>>n;
    vector<string> v(n,"");
    for (int i=0;i<n;++i)
    {
        cin>>s;
        for (auto j : s)
            v[i]+=m1[j];
    }
    // for (auto i : v)
    //     cout<<i<<"\n";
    // cout<<"\n";
    sort(v.begin(), v.end());
    // for (auto i : v)
    //     cout<<i<<"\n";
    // cout<<"\n";
    for (auto i : v)
    {
        for (auto j : i)
            cout<<m2[j];
        cout<<"\n";
    }
    return 0;
}