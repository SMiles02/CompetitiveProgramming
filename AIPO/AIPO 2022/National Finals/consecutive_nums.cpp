#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 2e9;
int a[100000];

ll combine(int l, int r) {
    ll x = 0;
    for (int i = l; i <= r; ++i)
        x = x * 10 + a[i];
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, ans = 0, x;
    cin >> t >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (t == 1) {
        for (int i = 1; i < n; ++i)
            ans += (a[i] == a[i - 1] + 1);
    }
    else {
        for (int i = 0; i < n; ++i)
            if (a[i] != 0)
                for (int j = i + 1; j < n; ++j) {
                    x = combine(i, j);
                    if (x > INF || j + j - i + 1 >= n)
                        break;
                    if (x + 1 == combine(j + 1, j + j - i + 1))
                        ans = max(ans, x);
                }
    }
    cout << ans;
    return 0;
}