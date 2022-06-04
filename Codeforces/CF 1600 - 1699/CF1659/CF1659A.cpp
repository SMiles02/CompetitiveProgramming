#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, r, b;
    cin >> n >> r >> b;
    vector<int> v(b * 2 + 1, 1);
    r -= b + 1;
    while (r > 0)
        for (int i = 0; i < b * 2 + 1 && r--; i += 2)
            ++v[i];
    for (int i = 0; i < b * 2 + 1; ++i)
        while (v[i]--) {
            if (i & 1)
                cout << "B";
            else
                cout << "R";
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