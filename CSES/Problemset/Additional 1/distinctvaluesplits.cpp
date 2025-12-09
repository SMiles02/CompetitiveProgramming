#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0) x += MOD;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, last_dupe = 1;
    cin >> n;
    vector<int> p(n + 2);
    map<int, int> m;
    p[1] = 1;
    for (int i = 2, xi; i <= n + 1; ++i) {
        cin >> xi;
        last_dupe = max(last_dupe, m[xi]);
        m[xi] = i;
        p[i] = add(sub(p[i - 1], p[last_dupe - 1]), p[i - 1]);
    }
    cout << sub(p[n + 1], p[n]);
    return 0;
}