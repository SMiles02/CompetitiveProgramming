#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;
    bool done = false;
    vector<vector<int>> v(n + 1);
    vector<array<int, 2>> ans;
    for (int i = 2; i <= n; ++i) {
        v[1].push_back(i);
    }
    while (!done) {
        vector<vector<int>> w(n + 1);
        done = true;
        for (int i = 1; i <= n; ++i) {
            for (int j : v[i]) {
                int x = query(i, j);
                if (x == i) {
                    ans.push_back({i, j});
                }
                else {
                    w[x].push_back(j);
                    done = false;
                }
            }
        }
        swap(v, w);
    }
    cout << "!";
    for (auto [x, y] : ans) {
        cout << " " << x << " " << y;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}