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

map<array<ll,4>,ll> m;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,x,y,c,d,g,X,Y,ans=-1;
    cin>>n;
    ll a[n][3];
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<3;++j)
            cin>>a[i][j];
        a[i][0]*=2;
        a[i][1]*=2;
    }
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
        {
            x=a[i][0]-a[j][0];
            y=a[i][1]-a[j][1];
            X=(a[i][0]+a[j][0])/2;
            Y=(a[i][1]+a[j][1])/2;
            if (x==0)
            {
                y=696969;
                c=Y/2;
                d=696969;
            }
            else
            {
                g=gcd(abs(x),abs(y));
                x/=g;
                y/=g;
                if (x<0&&y<0)
                    x*=-1,y*=-1;
                else if (x<0&&y>=0)
                    x*=-1,y*=-1;
                c=Y*y-x*X;
                d=y;
                if (d==0)
                    c=696969;
                else
                {
                    g=gcd(abs(c),abs(d));
                    c/=g;
                    d/=g;
                    if (c<0&&d<0)
                        c*=-1,c*=-1;
                    else if (c>=0&&d<0)
                        c*=-1,d*=-1;
                }
            }
            cout<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<c<<" "<<d<<" "<<a[i][2]+a[j][2]<<"\n";
            if (m[{x,y,c,d}])
            {
                cout<<"!!!\n";
                ans=max(ans,m[{x,y,c,d}]+a[i][2]+a[j][2]);
            }
            m[{x,y,c,d}]=max(m[{x,y,c,d}],a[i][2]+a[j][2]);
        }
    cout<<ans;
    return 0;
}