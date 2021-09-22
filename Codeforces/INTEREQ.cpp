  
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

int a[101], rmn;
vector<int> v;

int query(int l, int r)
{
    cout<<"? ";
    for (int i=l;i<=r;++i)
        cout<<v[i]<<" ";
    cout<<endl;
    int val;
    cin>>val;
    return val;
}

void setTo(int x, int y)
{
    a[x]=y;
    --rmn;
}

void solve()
{
    int n, q, x=1, k, m, l, r, mid, s;
    cin>>n>>q;
    for (int i=;1;i<=n;++i)
        a[i]=0;
    rmn=n;
    while (rmn)
    {
        v.clear();
        for (int i=1;i<=n;++i)
            if (a[i]==0)
                v.push_back(i);
        m=sz(v);
        k=query(0,m-1);
        if (k==1)
        {
            for (int i : v)
                setTo(i,x++);
            break;
        }
        if (k==m)
        {
            for (int i : v)
                setTo(i,x);
            break;
        }
        s=0;
        while ()
    }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    // int n, ans=0;
    // cin>>n;
    // for (int i=2;i<=n;++i)
    //     ans+=__lg(i+1);
    // cout<<ans;
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}