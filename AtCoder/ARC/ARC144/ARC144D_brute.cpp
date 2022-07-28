#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5;
int n, pwr, k, k_max, a[N];
ll ans = 0;

void rec(int i) {
    if (i == n) {
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y)
                if (a[x] + a[y] != a[x & y] + a[x | y])
                    return;
        ++ans;
        for (int x = 0; x < n; ++x)
            cerr << a[x] << " ";
        cerr << "\n";
        return;
    }
    for (int j = 0; j <= k; ++j) {
        a[i] = j;
        rec(i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> pwr >> k_max;
    n = (1 << pwr);
    set<array<int, 4>> s;
    int A, B, C, D;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j) {
            A = i;
            B = j;
            C = i | j;
            D = i & j;
            if (C > D)
                swap(C, D);
            if (!(A == C && B == D)) {
                if (A > C || (A == C && B > D)) {
                    swap(A, C);
                    swap(B, D);
                }
                s.insert({A, B, C, D});
                // cout << i << " " << j << " " << A << " " << B << " " << C << " " << D << "\n";
            }
        }
    // for (auto i : s) {
    //     for (auto j : i)
    //         cout << j << " ";
    //     cout << "\n";
    // }
    for (k = 1; k <= k_max; ++k) {
        ans = 0;
        cerr << pwr << " " << k << ":\n";
        rec(0);
        cout << pwr << " " << k << ": " << ans << "\n";
    }
    return 0;
}