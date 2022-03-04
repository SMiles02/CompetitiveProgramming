#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, a[3001];
bool local = 0;

int query(int x, int y, int z) {
    cout << "? " << x << " " << y << " " << z << endl;
    if (local) {
        if (x == y || x == z || y == z)
            cerr << "Duplicate used" << endl;
        cout << "Query answer: " << max({a[x], a[y], a[z]}) - min({a[x], a[y], a[z]}) << endl;
        return max({a[x], a[y], a[z]}) - min({a[x], a[y], a[z]});
    }
    int ret;
    cin >> ret;
    return ret;
}

void answer(int x, int y) {
    cout << "! " << x << " " << y << endl;
    if (local && (a[x] != 0 && a[y] != 0))
        cerr << "Wrong answer" << endl;
}

void solve() {
    int x, y, z, s, t, u, a1, a2, og, q, mx = 0;
    cin >> n;
    if (local)
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
    if (n == 4) {
        int ans[5][5][5];
        for (int i = 1; i < 5; ++i)
            for (int j = i + 1; j < 5; ++j)
                for (int k = j + 1; k < 5; ++k) {
                    ans[i][j][k] = query(i, j, k);
                    mx = max(mx, ans[i][j][k]);
                }
        for (int i = 1; i < 5; ++i)
            for (int j = i + 1; j < 5; ++j) {
                // cerr << i << " " << j << endl;
                bool ok = 1;
                for (int k = 1; k < 5; ++k)
                    if (k != i && k != j) {
                        int tmp[3] = {i, j, k};
                        sort(tmp, tmp + 3);
                        // cerr << tmp[0] << " " << tmp[1] << " " << tmp[2] << endl;
                        if (ans[tmp[0]][tmp[1]][tmp[2]] != mx)
                            ok = 0;
                    }
                if (ok) {
                    answer(i, j);
                    return;
                }
            }
        cerr << "wtf" << endl;
        answer(1, 2);
        return;
    }
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    shuffle(v.begin(), v.end(), rng);
    s = v[0];
    t = v[1];
    u = v[2];
    x = v[n - 3];
    y = v[n - 2];
    z = v[n - 1];
    a1 = query(s, t, u);
    a2 = query(x, y, z);
    if (a1 < a2) {
        swap(a1, a2);
        swap(s, x);
        swap(t, y);
        swap(u, z);
    }
    mx = a2;
    og = z;
    for (int i : v)
        if (i != x && i != y && i != og) {
            q = query(x, y, i);
            if (q > mx) {
                mx = q;
                z = i;
            }
        }
    swap(x, z);
    // now, x is either the min (0) or the max element
    if (local)
        cout << x << " is either the min or max" << endl;
    og = z;
    for (int i : v)
        if (i != x && i != y && i != og) {
            q = query(x, y, i);
            if (q > mx) {
                mx = q;
                z = i;
            }
        }
    // now either y or z are the opposite min/max of x
    for (int i : v)
        if (i != x && i != y && i != z) {
            q = query(x, z, i);
            if (q == mx)
                swap(y, z);
            break;
        }
    answer(x, y);
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}