#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

const int N = 3000;
int n, m;
bitset<N> good[N];
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

bool ok(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

int cnt(int x, int y) {
    int ret = 0;
    for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (ok(tx, ty) && good[tx][ty])
            ++ret;        
    }
    return ret;
}

void solve() {
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '#')
                good[i][j] = 0;
            else
                good[i][j] = 1;
        }
    }
    vector<array<int, 2>> v;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (good[i][j] && cnt(i, j) < 2) {
                good[i][j] = 0;
                v.push_back({i, j});
            }
    int x, y, tx, ty;
    while (!v.empty()) {
        x = v.back()[0];
        y = v.back()[1];
        v.pop_back();
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (ok(tx, ty) && good[tx][ty] && cnt(tx, ty) < 2) {
                good[tx][ty] = 0;
                v.push_back({tx, ty});
            }
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (good[i][j])
                s[i][j] = '^';
            else if (s[i][j] == '^') {
                cout << "Impossible\n";
                return;
            }
        }
    cout << "Possible\n";
    for (int i = 0; i < n; ++i)
        cout << s[i] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}