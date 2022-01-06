#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int n;
long long a[N], b[N], c[N];

bool check(int x) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i];
        c[i] = 0;
    }
    int k;
    for (int i = n - 1; i > 1; --i) {
        if (b[i] + c[i] < x)
            return 0;
        k = min(b[i] + c[i] - x, b[i])/3;
        c[i-1] += k;
        c[i-2] += k*2;
    }
    return (b[0] + c[0] >= x && b[1] + c[1] >= x);
}

void solve() {
    int l = 0, r = 1e9, m;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    while (l < r) {
        m = l + (r - l)/2 + 1;
        if (check(m))
            l = m;
        else
            r = m - 1;
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