#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q = -1;
    cin >> n;
    int a[n + 1];
    vector<vector<int>> cnt(6, vector<int>(10));
    while (true) {
        ++q;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            ++cnt[q][a[i]];
        }
        if (q > 0) {
            bool diff = false;
            for (int i = 1; i < 10; ++i) {
                diff |= cnt[q - 1][i] != cnt[q][i];
            }
            if (diff) {
                break;
            }
        }
        cout << "- 0" << endl;
    }
    int new_type = 0;
    for (int i = 1; i < 10; ++i) {
        if (cnt[q - 1][i] < cnt[q][i]) {
            new_type = i;
        }
    }
    cout << "- " << n - cnt[q][new_type];
    for (int i = 1; i <= n; ++i) {
        if (a[i] != new_type) {
            --cnt[q][a[i]];
            cout << " " << i;
        }
    }
    cout << endl;
    n = cnt[q][new_type];
    while (true) {
        ++q;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            ++cnt[q][a[i]];
        }
        bool diff = false;
        for (int i = 1; i < 10; ++i) {
            diff |= cnt[q - 1][i] != cnt[q][i];
        }
        if (diff) {
            break;
        }
        cout << "- 0" << endl;
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] != new_type) {
            cout << "! " << i << endl;
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}