#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 5e5 + 1;
int n, m, a[N];
array<int, 2> b[N];
bitset<N> beat;

void solve() {
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = {a[i], i};
        beat[i] = 0;
    }
    sort(b, b + n);
    for (int i = 0; i < n && m >= b[i][0]; ++i) {
        m -= b[i][0];
        ++cnt;
        beat[b[i][1]] = 1;
    }
    if (cnt == 0)
        cout << n + 1 << "\n";
    else if (cnt == n)
        cout << "1\n";
    else if (beat[cnt] || m + b[cnt - 1][0] >= a[cnt])
        cout << n - cnt << "\n";
    else
        cout << n - cnt + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}