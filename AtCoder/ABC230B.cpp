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
    string s;
    cin>>s;
    for (int x=0;x<2;++x)
        for (int y=0;y<2;++y)
            for (int z=0;z<2;++z)
                if (x+y+z==1)
                {
                    bool ok=1;
                    vector<int> v = {x,y,z};
                    for (int i=0;i<sz(s);++i)
                    {
                        if (s[i]=='o'&&v[i%3]==1)
                            continue;
                        if (s[i]=='x'&&v[i%3]==0)
                            continue;
                        ok=0;
                    }
                    if (ok)
                    {
                        cout<<"Yes";
                        return 0;
                    }
                }
    cout<<"No";
    return 0;
}