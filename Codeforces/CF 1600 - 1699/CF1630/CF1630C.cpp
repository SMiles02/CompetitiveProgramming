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
    int n, k, ans = 0, l, r, x;
    cin >> n;
    int a[n + 1];
    vector<vector<int>> v(n + 1);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        if (v[i].size() > 1)
            pq.push({v[i].back(), v[i][0]});
    while (!pq.empty()) {
        l = pq.top()[1];
        r = pq.top()[0];
        pq.pop();
        x = 1;
        while (!pq.empty() && pq.top()[1] < r) {
            l = min(l, pq.top()[1]);
            r = pq.top()[0];
            pq.pop();
            ++x;
        }
        ans += r - l - x;
    }
    cout << ans;
    return 0;
}