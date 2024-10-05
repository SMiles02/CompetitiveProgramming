#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e7 + 5;
bitset<N> sieve;

void solve() {
    int n;
    cin >> n;
    if (n < 5) {
        cout << "0\n";
        return;
    }
    int ans = 1;
    for (int i = 3; i + 2 <= n; ++i) {
        if (!sieve[i] && !sieve[i + 2]) {
            ++ans;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < N; ++i) {
        if (sieve[i]) {
            continue;
        }
        for (int j = i * 2; j < N; j += i) {
            if (j % i == 0) {
                sieve[j] = 1;
            }
        }
    }
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}