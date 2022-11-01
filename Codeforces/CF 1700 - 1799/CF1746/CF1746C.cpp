#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
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
    int n, x, y, z;
    cin >> n;
    int a[n + 1];
    priority_queue<array<int, 2>> pq;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 2; i <= n; ++i)
        if (a[i - 1] > a[i])
            pq.push({a[i - 1] - a[i], i});
    for (int i = n; i >= 1; --i) {
        if (!pq.empty()) {
            array<int, 2> tmp = pq.top();
            pq.pop();
            tmp[0] -= i;
            ans[i] = tmp[1];
            if (tmp[0] > 0)
                pq.push(tmp);
        }
        else
            ans[i] = 1;
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
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