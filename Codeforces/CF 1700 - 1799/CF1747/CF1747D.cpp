#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;
int a[N];
long long p[N], x[N];
map<int, set<int>> s[2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, l, r;
    cin >> n >> q;
    s[0][0].insert(0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
        x[i] = x[i - 1] ^ a[i];
        s[i & 1][x[i]].insert(i);
    }
    while (q--) {
        cin >> l >> r;
        if (p[l - 1] == p[r])
            cout << "0\n";
        else if (x[l - 1] != x[r])
            cout << "-1\n";
        else if ((r - l + 1) & 1)
            cout << "1\n";
        else if (min(a[l], a[r]) == 0)
            cout << "1\n";
        else if (s[1 - ((l - 1) & 1)][x[l - 1]].upper_bound(l - 1) != s[1 - ((l - 1) & 1)][x[l - 1]].end() && *s[1 - ((l - 1) & 1)][x[l - 1]].upper_bound(l - 1) < r)
            cout << "2\n";
        else
            cout << "-1\n";
    }
    return 0;
}