#include <bits/stdc++.h>
using namespace std;

const int N = 6e5 + 3;
int to[N];
vector<int> from[N];

void get_cards(int& n, vector<array<int, 3>>& a, int x) {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][2] = x + i;
        to[x + i] = 0;
        from[x + i].clear();
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i][1];
    }
}

bool sort_atk(array<int, 3>& a, array<int, 3>& b) {
    return a[0] < b[0];
}

bool sort_def(array<int, 3>& a, array<int, 3>& b) {
    return a[1] < b[1];
}

void add_edges(int n, int m, vector<array<int, 3>>& a, vector<array<int, 3>>& b) {
    sort(a.begin(), a.end(), sort_def);
    sort(b.begin(), b.end(), sort_atk);
    int max_def = m - 1, p = m - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (b[m - 1][0] <= a[i][1]) {
            continue;
        }
        while (p > 0 && b[p - 1][0] > a[i][1]) {
            if (b[--p][1] > b[max_def][1]) {
                max_def = p;
            }
        }
        from[b[max_def][2]].push_back(a[i][2]);
        ++to[a[i][2]];
    }
}

void solve() {
    int n, m, w = 0, l = 0, d = 0;
    vector<array<int, 3>> a, b;
    get_cards(n, a, 0);
    get_cards(m, b, n);
    add_edges(n, m, a, b);
    add_edges(m, n, b, a);
    vector<int> s(n + m), v;
    for (int i = 0; i < n + m; ++i) {
        if (to[i] == 0) {
            s[i] = 1;
            v.push_back(i);
        }
    }
    while (!v.empty()) {
        int x = v.back();
        v.pop_back();
        if (s[x] == 1) {
            for (int i : from[x]) {
                if (--to[i] == 0 && s[i] == 0) {
                    s[i] = 2;
                    v.push_back(i);
                }
            }
        }
        else {
            for (int i : from[x]) {
                if (s[i] == 0) {
                    s[i] = 1;
                    v.push_back(i);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == 1) {
            ++w;
        }
        else if (s[i] == 2) {
            ++l;
        }
        else {
            ++d;
        }
    }
    cout << w << " " << d << " " << l << "\n";
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