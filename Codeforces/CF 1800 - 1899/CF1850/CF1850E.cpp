#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int n, a[N];

long long check(long long m) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (m * 2 + a[i]) * (m * 2 + a[i]); 
    }
    return sum;
}

void solve() {
    long long c, l = 0, r = 1;
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (check(r * 2) <= c) {
        r *= 2;
    }
    r *= 2;
    while (l < r) {
        long long m = l + (r - l) / 2 + 1;
        if (check(m) <= c) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}