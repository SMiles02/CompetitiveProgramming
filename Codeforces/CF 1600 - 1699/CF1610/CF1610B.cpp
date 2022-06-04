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

int n, a[200000];

bool ok(int x)
{
    int l=0,r=n-1;
    while (l<r)
    {
        if (a[l]==a[r])
        {
            ++l;
            --r;
        }
        else if (a[l]==x)
            ++l;
        else if (a[r]==x)
            --r;
        else
            return 0;
    }
    return 1;
}

void solve() {
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    int x=0,y=n-1;
    while (x<y)
    {
        if (a[x]==a[y])
        {
            ++x;
            --y;
        }
        else
        {
            if (ok(a[x])||ok(a[y]))
                cout<<"YES\n";
            else
                cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}