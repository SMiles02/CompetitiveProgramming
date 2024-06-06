#include <bits/stdc++.h>
using namespace std;

void add(multiset<array<int, 2>>& s, int x, int y) {
    s.insert({min(x, y), max(x, y)});
}

void flip(vector<int>& a, int l, int r) {
    vector<int> b = a;
    for (int i = l; i <= r; ++i) {
        a[i] = b[l + r - i];
    }
}

void solve() {
    int n;
    cin >> n;
    multiset<array<int, 2>> s, t;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i > 1) {
            add(s, a[i - 1], a[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        if (i > 1) {
            add(t, b[i - 1], b[i]);
        }
    }
    if (s != t || a[1] != b[1] || a[n] != b[n]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<array<int, 2>> ans;
    for (int i = 2; i < n; ++i) {
        for (int j = i + 1; j <= n && a[i] != b[i]; ++j) {
            if (a[i - 1] == a[j] && b[i] == a[j - 1]) {
                flip(a, i - 1, j);
                ans.push_back({i - 1, j});
            }
        }
        if (a[i] != b[i]) {
            int found_id = 0;
            map<int, int> mp;
            mp[a[i - 1]] = i - 1;
            for (int j = i; j <= n; ++j) {
                if (a[i - 1] == a[j - 1] && b[i] == a[j]) {
                    found_id = j - 1;
                }
                if (mp[a[j]] && mp[a[j]] <= found_id) {
                    flip(a, mp[a[j]], j);
                    ans.push_back({mp[a[j]], j});
                    break;
                }
                if (!mp[a[j]]) {
                    mp[a[j]] = j;
                }
            }
        }
        for (int j = i + 1; j <= n && a[i] != b[i]; ++j) {
            if (a[i - 1] == a[j] && b[i] == a[j - 1]) {
                flip(a, i - 1, j);
                ans.push_back({i - 1, j});
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i[0] << " " << i[1] << "\n";
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