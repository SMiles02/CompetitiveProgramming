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

int inp[10005];
bool local = 0;

int query(int op, int x, int y)
{
    int z;
    if (op==0)
    {
        if (local)
            return inp[x]|inp[y];
        cout<<"or ";
    }
    else
    {
        if (local)
            return inp[x]&inp[y];
        cout<<"and ";
    }
    cout<<x<<" "<<y<<endl;
    cin>>z;
    return z;
}

int XOR(int o, int a)
{
    return o-a;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,a,b,c,d,e;
    cin>>n>>k;
    if (local)
        for (int i=1;i<=n;++i)
            cin>>inp[i];
    int v[n+1];
    a=query(0,1,2);
    b=query(1,1,2);
    c=query(0,1,3);
    d=query(1,1,3);
    e=query(0,2,3);
    v[1]=b|d|(a&~e)|(c&~e);
    v[2]=v[1]^XOR(a,b);
    v[3]=v[1]^XOR(c,d);
    for (int i=4;i<=n;++i)
    {
        a=query(0,1,i);
        b=query(1,1,i);
        v[i]=v[1]^XOR(a,b);
    }
    // for (int i=1;i<=n;++i)
    //     cout<<v[i]<<" ";
    sort(v+1,v+n+1);
    cout<<"finish "<<v[k]<<endl;
    return 0;
}