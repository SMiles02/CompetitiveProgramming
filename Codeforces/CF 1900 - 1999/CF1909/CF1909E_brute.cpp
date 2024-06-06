#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve(int n) {
    int cnt = 0;
    vector<int> v;
    for (int i = 1; i < (1 << n); ++i) {
        bool sim = false;
        for (int j : v) {
            if ((j & i) == j) {
                sim = true;
                break;
            }
        }
        if (sim) {
            continue;
        }
        int on = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                for (int k = j; k < n; k += j + 1) {
                    on ^= 1 << k;
                }
            }
        }
        if (__builtin_popcount(on) <= n / 5) {
            cout << i << ": ";
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    cout << j + 1 << " ";
                }
            }
            cout << "\n";
            ++cnt;
            v.push_back(i);
        }
    }
    cerr << n << ": " << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i <= 19; ++i) {
        cout << "Trying " << i << "\n";
        solve(i);
    }
    return 0;
}