// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2, C = 50;
int a[N], b[C];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (q--) {
        int l, r, m;
        cin >> l >> r;
        m = r - l + 1;
        if (m > C) {
            cout << "YES\n";
            continue;
        }
        for (int i = l; i <= r; ++i) {
            b[i - l] = a[i - 1];
        }
        sort(b, b + m);
        bool ans = false;
        for (int i = 5; i < m && !ans; ++i) {
            for (int j = 2; j < i && !ans; ++j) {
                vector<int> v;
                if (i - 1 == j) {
                    v = {b[i - 2], b[i - 3], b[i - 4], b[i - 5]};
                }
                else if (i - 2 == j) {
                    v = {b[i - 1], b[i - 3], b[i - 4], b[i - 5]};
                }
                else {
                    if (b[i - 1] + b[i - 2] > b[i] && b[j - 1] + b[j - 2] > b[j]) {
                        ans = true;
                    }
                    continue;
                }
                long long sum = 0LL + v[0] + v[1] + v[2] + v[3];
                for (int x = 2; x >= 0 && v[x] <= b[j]; --x) {
                    for (int y = x + 1; y < 4; ++y) {
                        if (v[x] + v[y] > b[j] && sum - v[x] - v[y] > b[i]) {
                            ans = true;
                        }
                    }
                }
            }
        }
        if (ans) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}