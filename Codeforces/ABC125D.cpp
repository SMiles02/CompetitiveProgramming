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

const int N = 1e5+1;
int f[N], b[N];
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,t,x,y;
    cin>>n>>q;
    while (q--)
    {
        cin>>t;
        if (t==1)
        {
            cin>>x>>y;
            f[y]=x;
            b[x]=y;
        }
        else if (t==2)
        {
            cin>>x>>y;
            f[y]=0;
            b[x]=0;
        }
        else
        {
            cin>>x;
            while (f[x]!=0)
                x=f[x];
            vector<int> v;
            while (x!=0)
            {
                v.push_back(x);
                x=b[x];
            }
            cout<<sz(v)<<" ";
            for (int i : v)
                cout<<i<<" ";
            cout<<"\n";
        }
    }
    return 0;
}