#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, x, y;
    cin >> n >> m;
    string s(m, 'B');
    while (n--) {
        cin >> x;
        y = m - x--;
        if (x > y)
            swap(x, y);
        if (s[x] == 'B')
            s[x] = 'A';
        else
            s[y] = 'A';
    }
    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}