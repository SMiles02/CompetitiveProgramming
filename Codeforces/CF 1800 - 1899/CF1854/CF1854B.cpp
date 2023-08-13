#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int a[N];
long long dp[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            dp[j] = max(dp[j] + a[i], dp[min(n - 1, j + a[i])]);
        }
    }
    cout << dp[0];
    return 0;
}