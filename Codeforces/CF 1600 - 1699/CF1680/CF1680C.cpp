#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int n, p[N];
vector<int> v;

bool check(int k) {
    if (min(p[n] - p[v[k]], p[v[v.size() - k - 1]]) <= k)
        return true;
    for (int i = 1; i + k < v.size(); ++i)
        if (p[v[i - 1]] + p[n] - p[v[i + k]] <= k)
            return true;
    return false;
}

void solve() {
    string s;
    cin >> s;
    n = s.size();
    v.clear();
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i] + (s[i] - '0');
        if (s[i] == '0')
            v.push_back(i + 1);
    }
    if (v.empty()) {
        cout << "0\n";
        return;
    }
    if (v[v.size() - 1] == v.size() || v[0] == n - v.size() + 1) {
        cout << "0\n";
        return;
    }
    for (int i = 1; i < v.size(); ++i) {
        if (v[i - 1] == i && v[i] == n - (v.size() - i) + 1) {
            cout << "0\n";
            return;
        }
    }
    int l = 1, r = v.size(), m;
    while (l < r) {
        m = l + (r - l) / 2;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}