#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 22;
int n;
ll a[N];
vector<array<int, 2>> ans;

void add(int i, int j) {
    a[i] += a[j];
    ans.push_back({i, j});
}

void solve() {
    cin >> n;
    array<ll, 2> mn = {21, 0}, mx = {-21, 0};
    ans.clear();
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mn = min(mn, {a[i], i});
        mx = max(mx, {a[i], i});
    }
    if (mn[0] == 0 && mx[0] == 0) {
        cout << "0\n";
        return;
    }
    if (mn[0] < 0) {
        while (a[mn[1]] >= -20) {
            add(mn[1], mn[1]);
        }
        add(n - 1, mn[1]);
        add(n - 1, mn[1]);
        for (int i = n - 2; i >= 0; --i) {
            add(i, i + 1);
            add(i, i + 1);
        }
    }
    else {
        while (a[mx[1]] <= 20) {
            add(mx[1], mx[1]);
        }
        add(0, mx[1]);
        for (int i = 1; i < n; ++i) {
            add(i, i - 1);
            add(i, i - 1);
        }
    }
    cout << ans.size() << "\n";
    // for (int i = 0; i < n; ++i) {
    //     cout << a[i] << " ";
    // }
    // cout << "!\n";
    for (auto [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}