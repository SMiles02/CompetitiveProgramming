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

const int N = 2e5+1;
int to[N], ans[N];
vector<int> from[N];

void solve()
{
    int n,x,y,finalAns=1,ct;
    cin>>n;
    ct=0;
    for (int i=1;i<=n;++i)
    {
        to[i]=0;
        from[i].clear();
        ans[i]=1;
    }
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        to[i]+=x;
        while (x--)
        {
            cin>>y;
            from[y].push_back(i);
        }
    }
    vector<int> v;
    for (int i=1;i<=n;++i)
        if (to[i]==0)
            v.push_back(i);
    while (!v.empty())
    {
        x=v.back();
        v.pop_back();
        ++ct;
        finalAns=max(finalAns,ans[x]);
        for (int i : from[x])
        {
            if (--to[i]==0)
            {
                v.push_back(i);
            }
            if (x<i)
                ans[i]=max(ans[i],ans[x]);
            else
                ans[i]=max(ans[i],ans[x]+1);
        }
    }
    if (ct!=n)
        finalAns=-1;
    cout<<finalAns<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}