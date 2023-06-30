#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        double cur = 0;
        for (int j = 1; j <= a[i]; ++j)
            for (int k = 0; k < i; ++k)
                if (a[k] > j)
                    cur += double(a[k] - j) / a[k];
        ans += cur / a[i];
    }
    cout << fixed << setprecision(6) << ans;
    return 0;
}