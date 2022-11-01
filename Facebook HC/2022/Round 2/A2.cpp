#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 1, H = 20, INF = 1e9;
int n, bit[H][N], hasher[H][N], a[N];
set<array<int, 2>> s[H];

void bit_refresh() {
    for (int i = 0; i < H; ++i) {
        for (int j = 1; j <= n; ++j)
            bit[i][j] = 0;
        s[i].clear();
        s[i].insert({INF * 2 + 1, INF * 2 + 1});
    }
}

int query(int x, int y) {
    int ret = 0;
    for (int i = y; i; i -= (i & -i))
        ret ^= bit[x][i];
    return ret;
}

int query(int x, int l, int r) {
    return query(x, r) ^ query(x, l - 1);
}

void update(int x, int y, int d) {
    for (int i = y; i <= n; i += (i & -i))
        bit[x][i] ^= d;
}

bool ok(int l, int m1, int m2, int r) {
    // cerr << l << " " << m1 << " " << m2 << " " << r << "\n";
    for (int j = 0; j < H; ++j) {
        int x = query(j, l, m1), y = query(j, m2, r), z;
        // cerr << x << " " << y << "\n";
        z = x ^ y;
        array<int, 2> a = *s[j].lower_bound({z, l});
        if (!(a[0] == z && a[1] <= m1))
            return false;
    }
    return true;
}

void solve() {
    cin >> n;
    bit_refresh();
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int j = 0; j < H; ++j)
        for (int i = 1; i <= n; ++i) {
            update(j, i, hasher[j][a[i]]);
            s[j].insert({hasher[j][a[i]], i});
        }
    int q, t, l, r, ans = 0;
    bool tmp;
    cin >> q;
    while (q--) {
        cin >> t >> l >> r;
        if (t == 1) {
            for (int j = 0; j < H; ++j) {
                update(j, l, hasher[j][a[l]] ^ hasher[j][r]);
                s[j].erase({hasher[j][a[l]], l});
                s[j].insert({hasher[j][r], l});
            }
            a[l] = r;
            // cerr << "Update\n";
        }
        else {
            if ((r - l) & 1) {
                // cerr << "Not odd\n";
                continue;
            }
            if (l == r) {
                // cerr << "Len 1\n";
                ++ans;
                continue;
            }
            tmp = (ok(l, l + (r - l) / 2, l + (r - l) / 2 + 1, r) || ok(l + (r - l) / 2, r, l, l + (r - l) / 2 - 1));
            ans += tmp;
            // if (tmp)
            //     cerr << "Yeah\n";
            // else
            //     cerr << "Nah\n";
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < H; ++i)
        for (int j = 1; j < N; ++j) {
            hasher[i][j] = uniform_int_distribution<int>(1, INF)(rng);
            // hasher[i][j] = j;
        }
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}