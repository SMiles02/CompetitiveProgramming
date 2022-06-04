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

void solve() {
    int n, k, done = 0, mn = -1, mx = -1;
    cin >> n;
    vector<int> ans;
    vector<deque<int>> v(n + 3);
    for (int i = 0; i < n; ++i) {
        cin >> k;
        v[k].push_back(i);
    }
    while (!v[0].empty()) {
        for (int i = 0; i <= n + 2; ++i) {
            while (!v[i].empty() && v[i].front() <= mn)
                v[i].pop_front();
            if (v[i].empty()) {
                ans.push_back(i);
                break;
            }
            else
                mx = max(mx, v[i].front());
        }
        mn = mx;
        while (!v[0].empty() && v[0].front() <= mn)
            v[0].pop_front();
    }
    for (int i = 0; i <= n + 2; ++i) {
        while (!v[i].empty() && v[i].front() <= mx)
            v[i].pop_front();
        while (!v[i].empty()) {
            v[i].pop_front();
            ans.push_back(0);
        }
    }
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i << " ";
    cout << "\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}