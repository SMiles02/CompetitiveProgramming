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
    int n;
    cin >> n;
    vector<int> a(n + 2), prev(n + 2), next(n + 2);
    a[0] = a[n + 1] = -69;
    priority_queue<array<int, 2>> pq;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pq.push({a[i], i});
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    while (pq.size() > 0) {
        int i = pq.top()[1];
        cout << i << "\n";
        pq.pop();
        if (a[i] != max(a[prev[i]], a[next[i]]) + 1) {
            cout << "NO\n";
            return;
        }
        next[prev[i]] = next[i];
        prev[next[i]] = prev[i];
    }
    if (pq.top()[0] == 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}