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

int d[26][26];

void solve()
{
    string s;
    cin>>s;
    char a,b;
    int ans=1e9,cur,n;
    for (int i=0;i<26;++i)
    {
        for (int j=0;j<26;++j)
            d[i][j]=1e7;
        d[i][i]=0;
    }
    cin>>n;
    while (n--)
    {
        cin>>a>>b;
        d[a-'A'][b-'A']=1;
    }
    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
    }
    for (char c='A';c<='Z';++c)
    {
        cur=0;
        for (auto i : s)
            cur+=d[i-'A'][c-'A'];
        ans=min(ans,cur);
    }
    if (ans>=1e7)
        ans=-1;
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}