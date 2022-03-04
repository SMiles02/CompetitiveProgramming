#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> ans;
    if (n == 4 && k == 3) {
        cout << "-1\n";
        return;
    }
    vector<bool> done(n);
    vector<int> v, w;
    for (int i = 0; i < 16; ++i)
        if ((1 << i) < n && ((1 << i) & k) == (1 << i)) {
            done[1 << i] = 1;
            done[n - 1 - (1 << i)] = 1;
            v.push_back(1 << i);
            w.push_back(n - 1 - (1 << i));
        }
    done[0] = done[n - 1] = 1;
    v.push_back(0);
    w.push_back(n - 1);
    for (int i = 0; i < n / 2; ++i)
        if (!done[i])
            ans.push_back({i, n - i - 1});
    for (int i : v) {
        vector<int> newW;
        for (int j : w)
            if ((i & j) == i) {
                ans.push_back({i, j});
                for (int x : w)
                    if (x != j)
                        newW.push_back(x);
                break;
            }
        swap(newW, w);
    }
    for (auto i : ans)
        cout << i[0] << " " << i[1] << "\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while (n--)
        solve();
    return 0;
}