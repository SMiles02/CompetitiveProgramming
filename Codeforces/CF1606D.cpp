//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5e5+7, MOD = 1e9+7;
int b1[N], b2[N];

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}

void solve()
{
    int n,m,c1,c2,k;
    cin>>n>>m;
    vector<vector<int>>  a(n,vector<int>(m));
    vector<int> mn(n,1e6), mx(n), sf(n);
    vector<array<int,2>> v(n);
    vector<set<ll>> s(m);
    for (int i=0;i<m;++i)
        s[i].clear();
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>a[i][j];
    for (int j=0;j+1<m;++j)
    {
        for (int i=0;i<n;++i)
        {
            mn[i]=min(mn[i],a[i][j]);
            mx[i]=max(mx[i],a[i][j]);
            v[i]={mx[i],i};
        }
        c1=c2=0;
        sort(v.begin(), v.end());
        sf[n-1]=mn[v[n-1][1]];
        for (int i=n-2;i>=0;--i)
            sf[i]=min(sf[i+1],mn[v[i][1]]);
        for (int i=0;i+1<n;++i)
        {
            c1=add(c1,b1[v[i][1]]);
            c2=add(c2,b2[v[i][1]]);
            if (v[i][0]<sf[i+1])
                s[j].insert(1LL*c1*MOD+c2);
        }
    }
    for (int i=0;i<n;++i)
    {
        mn[i]=1e6;
        mx[i]=0;
    }
    for (int j=m-1;j>0;--j)
    {
        for (int i=0;i<n;++i)
        {
            mn[i]=min(mn[i],a[i][j]);
            mx[i]=max(mx[i],a[i][j]);
            v[i]={mx[i],i};
        }
        c1=c2=0;
        sort(v.begin(), v.end());
        k=1e6;
        for (int i=n-1;i>0;--i)
        {
            c1=add(c1,b1[v[i][1]]);
            c2=add(c2,b2[v[i][1]]);
            k=min(k,mn[v[i][1]]);
            if (v[i-1][0]<k&&s[j-1].count(1LL*c1*MOD+c2))
            {
                cout<<"YES\n";
                string ans(n, 'R');
                for (int J=i;J<n;++J)
                    ans[v[J][1]]='B';
                cout<<ans<<" "<<j<<"\n";
                return;
            }
        }
    }
    cout<<"NO\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    b1[0]=1;
    b1[1]=uniform_int_distribution<int>(1000,10000)(rng);
    for (int i=2;i<N;++i)
        b1[i]=(1LL*b1[i-1]*b1[1])%MOD;
    b2[0]=1;
    b2[1]=uniform_int_distribution<int>(1000,10000)(rng);
    for (int i=2;i<N;++i)
        b2[i]=(1LL*b2[i-1]*b2[1])%MOD;
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}