#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
const long long INF = 1e18;
int a[N], b[N];
long long dp[N][2];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == k) {
            a[i] = 0;
        }
    }
    b[0] = 0;
    dp[0][0] = a[0];
    dp[0][1] = a[0] + k;
    for (int i = 1; i < n; ++i) {
        if (b[i - 1] > 0 && a[i] == )
    } 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}