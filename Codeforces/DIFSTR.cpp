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

bitset<100> ans;

void solve()
{
    int n;
    cin>>n;
    string s[n];
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n;++i)
        ans[i]=0;
    while (1)
    {
        bool ok=1, cur;
        for (int i=0;i<n;++i)
        {
            cur=0;
            for (int j=0;j<n;++j)
                cur|=(ans[j]!=s[i][j]-'0');
            ok&=cur;
        }
        if (ok)
        {
            for (int i=0;i<n;++i)
                cout<<ans[i];
            cout<<"\n";
            return;
        }
        for (int i=0;i<n;++i)
        {
            if (ans[i]==0)
            {
                ans[i]=1;
                break;
            }
            ans[i]=0;
        }
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