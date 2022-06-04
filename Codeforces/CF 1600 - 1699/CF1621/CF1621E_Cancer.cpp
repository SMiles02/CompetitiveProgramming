// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

// Unfinished...

bool cmp(array<ll, 3>& a, array<ll, 3>& b) {
    return 1LL*a[0]*b[1] < 1LL*b[0]*a[1];
}

bool gE(ll a, ll b, ll c, ll d) {
    return (a * d >= c * b);
}

void solve() {
    int n, m, k, x, cur = -1;
    cin >> n >> m;
    vector<int> a;
    ll s;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        a.push_back(k);
    }
    sort(a.rbegin(), a.rend());
    while (sz(a)>m)
        a.pop_back();
    a.push_back(0);
    sort(a.begin(), a.end());
    vector<vector<int>> v(m+1);
    string ans(m, '0');
    array<ll,3> b[m+2];
    b[0]={0,1,0};
    b[m+1]={1000000,1,0};
    vector<int> p(m+2), dn(m+2), up(m+2);
    for (int i=1;i<=m;++i)
    {
        cin>>k;
        s=0;
        for (int j=0;j<k;++j) {
            cin>>x;
            s+=x;
            v[i].push_back({x,++cur});
        }
        b[i]={s,k,i};
    }
    sort(b,b+m+2,cmp);
    p[0]=1;
    dn[0]=1;
    for (int i=1;i<=m;++i) {
        p[i] = p[i-1] + !gE(a[i], 1, b[i][0], b[i][1]);
        dn[i] = dn[i-1] + !gE(a[i], 1, b[i+1][0], b[i+1][1]);
        up[i] = up[i-1] + !gE(a[i], 1, b[i-1][0], b[i-1][1]);
    }
    for (int i=1;i<=m;++i)
        for (int j : v[b[i][2]]) {
            if (gE(b[i][0],b[i][1],b[i][0]-j,b[i][1]-1)) {
                if (gE(b[1][0],b[1][1],b[i][0]-j,b[i][1]-1)) {
                    if (up[i-1] == up[0] && p[n] == p[i+1] && gE(a[1],1,b[i][0]-j,b[i][1]-1))
                        s
                }
            }
        }
    cout<<ans<<"\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}