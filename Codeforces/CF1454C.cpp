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

vector<int> v[200001];

void solve()
{
    int n,k,ans,cur;
    cin>>n;
    ans=n;
    for (int i=1;i<=n;++i)
    {
        v[i].clear();
        v[i].push_back(0);
    }
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        v[k].push_back(i);
    }
    for (int i=1;i<=n;++i)
        if (sz(v[i])>1)
        {
            cur=0;
            for (int j=1;j<sz(v[i]);++j)
                if (v[i][j]-1>v[i][j-1])
                    ++cur;
            if (v[i].back()<n)
                ++cur;
            ans=min(ans,cur);
        }
    cout<<ans<<"\n";
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