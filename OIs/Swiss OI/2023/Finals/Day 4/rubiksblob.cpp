#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1, L = 45;
int a[N], dp[N][L];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 0; j < L; ++j)
            dp[i][j] = 
    }
    return 0;
}