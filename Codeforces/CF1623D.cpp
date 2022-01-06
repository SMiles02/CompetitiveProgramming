// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 1e9+7, N = 2e5+1;
int f[N];

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int mul(int a, int b) { return (1LL*a*b)%MOD; }

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b) { return mul(a,binpow(b,MOD-2)); }

int sub(int a, int b) { return add(a,MOD-b); }

void solve() {
    int n,m,a,b,c,d,p,q,x=1,y=1,rp1,rp2,ans=0;
    cin>>n>>m>>a>>b>>c>>d>>p;
    p=dv(p,100);
    q=sub(1,p);
    map<array<int,4>,int> mp;
    // posX, posY, dirX, dirY
    vector<array<int,5>> v = {{69,69,69,69,0}};
    // last spot is count of viables
    for (int i=1;;++i)
    {
        if (!(1<=a+x&&a+x<=n))
            x*=-1;
        if (!(1<=b+y&&b+y<=m))
            y*=-1;
        if (mp[{a,b,x,y}])
        {
            rp1 = mp[{a,b,x,y}];
            rp2 = i-1;
            break;
        }
        mp[{a,b,x,y}]=i;
        ans=add(ans,mul(i,mul(p,binpow(q,v.back()[4]))));
        v.push_back({a,b,x,y,v.back()[4]+(a==c||b==d)});
        a+=x;
        b+=y;
    }
    // for (int i=1;i<sz(v);++i)
    // {
    //     for (int j : v[i])
    //         cout<<j<<" ";
    //     cout<<"\n";
    // }
    // cout<<rp1<<" "<<rp2<<"\n";
    
    // cout<<ans<<"\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}