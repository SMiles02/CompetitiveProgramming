#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve() {
    int n, m, ans = 0;
    ll cur = 0;
    cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    priority_queue<int> p;
    for (int i = m; i > 1; --i) {
        cur += a[i];
        if (a[i] > 0)
            p.push(a[i]);
        while (cur > 0) {
            ++ans;
            cur -= p.top() * 2;
            p.pop();
        }
    }
    cur = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = m + 1; i <= n; ++i) {
        cur += a[i];
        if (a[i] < 0)
            q.push(a[i]);
        while (cur < 0) {
            ++ans;
            cur -= q.top() * 2;
            q.pop();
        } 
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}