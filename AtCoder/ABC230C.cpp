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
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,a,b,p,q,r,s,k;
    cin>>n>>a>>b;
    cin>>p>>q>>r>>s;
    for (ll i=p;i<=q;++i)
    {
        for (ll j=r;j<=s;++j)
        {
            k=i-a;
            if ((max(1-a,1-b)<=k&&k<=min(n-a,n-b)&&j-k==b)||(max(1-a,b-n)<=k&&k<=min(n-a,b-1)&&j+k==b))
                cout<<"#";
            else
                cout<<".";
        }
        cout<<"\n";
    }
    return 0;
}