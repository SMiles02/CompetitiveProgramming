#include <bits/stdc++.h>
using namespace std;

// not correct

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > n || ((a > 0) ^ (b > 0))) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> x(n), y(n);
    for (int i = 0; i < n - a - b; ++i) {
        x[i] = y[i] = i + 1;
    }
    deque<int> p, q;
    for (int i = n - a - b; i < n; ++i) {
        p.push_back(i + 1);
        q.push_back(i + 1);
    }
    for (int i = 0; i < a; ++i) {
        p.push_front(p.back());
        p.pop_back();
    }
    for (int i = 0; i < a + b; ++i) {
        x[n - a - b + i] = p[i];
        y[n - a - b + i] = q[i];
    }
    for (int i : x) {
        cout << i << " ";
    }
    cout << "\n";
    for (int i : y) {
        cout << i << " ";
    }
    cout << "\n";
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