#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, m;
vector<int> a[N], ans;
bitset<N> done;

bool rec(int d, vector<int> w) {
    if (d == m)
        return true;
    for (int i = 1; i <= m; ++i)
        if (!done[i]) {
            vector<int> v = w;
            bool ok = false;
            for (int j : a[i])
                if (v[j]-- > 0)
                    ok = true;
            if (ok) {
                done[i] = 1;
                if (rec(d + 1, v)) {
                    ans.push_back(i);
                    return true;
                }
                done[i] = 0;
            }
        }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k, x;
    cin >> n >> m;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    for (int i = 1; i <= m; ++i) {
        k = 2;
        while (k--) {
            cin >> x;
            a[i].push_back(x);
        }
    }
    if (rec(0, w)) {
        cout << "YES\n";
        // while (!ans.empty()) {
        //     cout << ans.back() << " ";
        //     ans.pop_back();
        // }
    }
    else
        cout << "NO\n";
    return 0;
}