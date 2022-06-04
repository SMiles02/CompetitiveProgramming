#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7, N = 2e6 + 1;
int dp[N];

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int mul(int a, int b) { return (1LL*a*b)%MOD; }
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 3; i < N; ++i) {
        dp[i] = add(dp[i - 1], mul(dp[i - 2], 2));
        if (i % 3 == 0)
            dp[i] = add(dp[i], 1);
    }
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << mul(dp[n], 4) << "\n";
    }
    return 0;
}