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

void solve()
{
    int W,H,w,h,x1,y1,x2,y2;
    cin>>W>>H;
    cin>>x1>>y1>>x2>>y2;
    cin>>w>>h;
    int ans = 1e9;
    if (w<=x1||h<=y1||x2+w<=W||y2+h<=H)
        ans=0;
    if (w+x2-x1<=W)
        ans=min({ans,abs(w-x1),abs(x2-W+w)});
    if (h+y2-y1<=H)
        ans=min({ans,abs(h-y1),abs(y2-H+h)});
    if (ans==1e9)
        cout<<"-1\n";
    else
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