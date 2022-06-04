// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

const int N = 1e6+1;
bitset<N> sieve;

void runSieve()
{
    sieve[1]=1;
    for (int i=4;i<N;i+=2)
        sieve[i]=1;
    for (int i=3;i<N;i+=2)
        if (!sieve[i])
            for (int j=i*3;j<N;j+=i*2)
                sieve[j]=1;
}

void solve() {
    int n,e,k;
    cin>>n>>e;
    vector<vector<int>> v(e);
    ll ans=0;
    for (int i=0;i<e;++i)
        v[i].push_back(69);
    for (int i=0;i<n;++i)
    {
        cin>>k;
        v[i%e].push_back(k);
    }
    for (int i=0;i<e;++i)
        v[i].push_back(69);
    for (int i=0;i<e;++i)
    {
        vector<int> l(sz(v[i])), r(sz(v[i]));
        for (int j=1;j+1<sz(v[i]);++j)
        {
            if (v[i][j]==1||sieve[v[i][j]]==0)
            {
                if (v[i][j-1]==1)
                    l[j]=l[j-1]+1;
                else
                    l[j]=1;
            }
            else
                l[j]=0;
        }
        for (int j=sz(v[i])-1;j>0;--j)
        {
            if (v[i][j]==1||sieve[v[i][j]]==0)
            {
                if (v[i][j+1]==1)
                    r[j]=r[j+1]+1;
                else
                    r[j]=1;
            }
            else
                r[j]=0;
        }
        // for (int j=1;j+1<sz(v[i]);++j)
        //     cout<<l[j]<<" ";
        // cout<<"\n";
        // for (int j=1;j+1<sz(v[i]);++j)
        //     cout<<r[j]<<" ";
        // cout<<"\n";
        for (int j=1;j+1<sz(v[i]);++j)
            if (!sieve[v[i][j]])
                ans+=1LL*l[j]*r[j]-1;
    }
    cout<<ans<<"\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    runSieve();
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}