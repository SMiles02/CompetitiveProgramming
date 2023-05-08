#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

bool collinear(array<int, 2>& p, array<int, 2>& q, array<int, 2>& r) {
    return (1LL * (p[0] - q[0]) * (q[1] - r[1]) == 1LL * (p[1] - q[1]) * (q[0] - r[0]));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "YES\n";
        return 0;
    }
    array<int, 2> a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i][0] >> a[i][1];
    for (int _ = 0; _ < 50; ++_) {
        int x = get_rand(0, n - 1), y = get_rand(0, n - 1);
        while (x == y)
            y = get_rand(0, n - 1);
        vector<int> v;
        for (int i = 0; i < n; ++i)
            if (!collinear(a[x], a[y], a[i]))
                v.push_back(i);
        bool ok = true;
        for (int i = 2; i < v.size(); ++i)
            ok &= collinear(a[v[0]], a[v[1]], a[v[i]]);
        if (ok) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}