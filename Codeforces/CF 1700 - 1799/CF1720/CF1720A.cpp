#include <bits/stdc++.h>
using namespace std;

bool is_good(int a, int b, int c, int d) {
    return (1LL * a * d) % (1LL * b * c) == 0;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (1LL * a * d == 1LL * b * c)
        cout << "0\n";
    else if (min(a, c) == 0 || is_good(a, b, c, d) || is_good(c, d, a, b))
        cout << "1\n";
    else
        cout << "2\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}