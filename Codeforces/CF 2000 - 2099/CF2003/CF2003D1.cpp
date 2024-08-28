#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

long long f(int x) {
    return (1LL * x * (x + 1)) / 2;
}

void solve() {
    int n, m, s = 0, maxi = 0;
    cin >> n >> m;
    vector<array<int, 2>> a(n, {-1, -1});
    for (int i = 0; i < n; ++i) {
        int k, x;
        cin >> k;
        s += k;
        vector<bool> b(k + 3);
        for (int j = 0; j < k; ++j) {
            cin >> x;
            b[min(x, k + 2)] = true;
        }
        for (int j = 0; j < k + 3; ++j) {
            if (b[j]) {
                continue;
            }
            if (a[i][0] == -1) {
                a[i][0] = j;
            }
            else {
                a[i][1] = j;
                break;
            }
        }
        maxi = max(maxi, a[i][1]);
    }
    vector<int> ans(s + 2, maxi);
    for (int i = 0; i < s + 2; ++i) {
        ans[i] = max(ans[i], i);
    }
    long long sum = 0;
    for (int i = 0; i <= min(s + 1, m); ++i) {
        sum += ans[i];
    }
    cout << sum + f(m) - f(min(s + 1, m)) << "\n";
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