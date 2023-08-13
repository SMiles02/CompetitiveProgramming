#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5 + 1;
int to[N], c[N];
vector<int> from[N], makes[N];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        to[i] = 0;
        from[i].clear();
        makes[i].clear();
    }
    while (k--) {
        int tmp;
        cin >> tmp;
        c[tmp] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        while (m--) {
            int e;
            cin >> e;
            ++to[i];
            from[e].push_back(i);
            makes[i].push_back(e);
        }
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        if (to[i] == 0) {
            v.push_back(i);
        }
    }
    while (!v.empty()) {
        int x = v.back();
        v.pop_back();
        for (int i : from[x]) {
            if (--to[i] == 0) {
                v.push_back(i);
            }
        }
        if (makes[x].empty()) {
            continue;
        }
        ll cur = 0;
        for (int i : makes[x]) {
            cur += c[i];
        }
        if (cur < c[x]) {
            c[x] = cur;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << c[i] << " ";
    }
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