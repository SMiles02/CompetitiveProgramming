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

const int maxn = 3e5+7;
int n,a[maxn],b[maxn],c[maxn];
 
ll find_inversions(int l, int r)
{
    if (l==r)
        return 0;
    int m=l+((r-l)>>1),x=l,y=m+1;
    ll ans=find_inversions(l,m)+find_inversions(m+1,r);
    for (int i=l;i<=r;++i)
    {
        if (x>m)
            c[i]=b[y++];
        else if (y>r)
            c[i]=b[x++];
        else if (b[x]>b[y])
        {
            c[i]=b[y++];
            ans+=m-x+1;
        }
        else
            c[i]=b[x++];
    }
    for (int i=l;i<=r;++i)
        b[i]=c[i];
    return ans;
}

vector<int> v[2];

void solve()
{
    int n,x,y;
    ll ans=1e18;
    cin>>n;
    v[0].clear();
    v[1].clear();
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        v[a[i]&1].push_back(i); 
    }
    if (max(sz(v[0]),sz(v[1]))>min(sz(v[0]),sz(v[1]))+1)
    {
        cout<<"-1\n";
        return;
    }
    if (sz(v[0])*2>=n)
    {
        x=0;
        y=0;
        for (int i=1;i<=n;++i)
        {
            if (i&1)
                b[v[0][x++]]=i;
            else
                b[v[1][y++]]=i;
        }
        ans=min(ans,find_inversions(1,n));
    }
    if (sz(v[1])*2>=n)
    {
        x=0;
        y=0;
        for (int i=1;i<=n;++i)
        {
            if (i&1)
                b[v[1][x++]]=i;
            else
                b[v[0][y++]]=i;
        }
        ans=min(ans,find_inversions(1,n));
    }
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}