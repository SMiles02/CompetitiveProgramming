#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
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

ll a[300000][2];
ll b[300000][5];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q;
    ll x,y;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i][0]>>a[i][1];
    cin>>m;
    b[0][2]=1;b[0][3]=1;
    for (int i=1;i<=m;++i)
    {
        for (int j=0;j<5;++j)
            b[i][j]=b[i-1][j];
        cin>>x;
        if (x==1)
        {
            swap(b[i][0],b[i][1]);
            swap(b[i][2],b[i][3]);
            b[i][3]*=-1;
            b[i][1]*=-1;
            b[i][4]^=1;
        }
        else if (x==2)
        {
            swap(b[i][0],b[i][1]);
            swap(b[i][2],b[i][3]);
            b[i][2]*=-1;
            b[i][0]*=-1;
            b[i][4]^=1;
        }
        else if (x==3)
        {
            cin>>y;
            b[i][2]*=-1;
            b[i][0]*=-1;
            b[i][0]+=2*y;
        }
        else
        {
            cin>>y;
            b[i][3]*=-1;
            b[i][1]*=-1;
            b[i][1]+=2*y;
        }
    }
    cin>>q;
    while (q--)
    {
        cin>>x>>y;
        if (b[x][4]==0)
            cout<<b[x][0]+b[x][2]*a[y][0]<<" "<<b[x][1]+b[x][3]*a[y][1]<<"\n";
        else
            cout<<b[x][0]+b[x][2]*a[y][1]<<" "<<b[x][1]+b[x][3]*a[y][0]<<"\n";
    }
    return 0;
}