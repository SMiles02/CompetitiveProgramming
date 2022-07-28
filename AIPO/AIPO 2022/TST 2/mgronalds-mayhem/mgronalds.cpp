#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
int a[N][2], w[N], d[N]; // favourite foods, number of plates of each originally, demand
vector<int> v[N]; // for each dish, the people that want it
bitset<N> served; // which people have been served

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    vector<int> ans, free;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    for (int i = 1; i <= m; ++i) {
        cin >> a[i][0] >> a[i][1];
        v[a[i][0]].push_back(i);
        v[a[i][1]].push_back(i);
        ++d[a[i][0]];
        ++d[a[i][1]];
    }
    for (int i = 1; i <= n; ++i) {
        d[i] -= w[i];
        if (d[i] <= 0)
            free.push_back(i);
    }
    while (!free.empty()) {
        x = free.back();
        free.pop_back();
        for (int i : v[x])
            if (!served[i]) {
                ans.push_back(i);
                served[i] = 1;
                for (int j = 0; j < 2; ++j)
                    if (--d[a[i][j]] == 0)
                        free.push_back(a[i][j]);
            }
    }
    if (ans.size() < m)
        cout << "NO\n";
    else {
        cout << "YES\n";
        // while (!ans.empty()) {
        //     cout << ans.back() << " ";
        //     ans.pop_back();
        // }
    }
    return 0;
}