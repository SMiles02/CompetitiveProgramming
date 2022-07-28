#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n;
    vector<int> v(10);
    for (int i = 0; i < n; ++i) {
        cin >> k;
        ++v[k % 10];
    }
    for (int i = 0; i < 10; ++i)
        if (v[i]) {
            --v[i];
            for (int j = i; j < 10; ++j)
                if (v[j]) {
                    --v[j];
                    for (int k = j; k < 10; ++k)
                        if (v[k] && (i + j + k) % 10 == 3) {
                            cout << "YES\n";
                            return;
                        }
                    ++v[j];
                }
            ++v[i];
        }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}