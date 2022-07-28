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

vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, x, y;
    cin >> n;
    ll ans = 0, cur;
    string s[n];
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < 8; ++k) {
                cur = s[i][j] - '0';
                x = i;
                y = j;
                for (int _ = 1; _ < n; ++_) {
                    x += dx[k];
                    y += dy[k];
                    x = (x + n) % n;
                    y = (y + n) % n;
                    // if (i == 1 && j == 3 && k == 7)
                    //     cout << x << " " << y << "\n";
                    cur = cur * 10 + (s[x][y] - '0');
                }
                ans = max(ans, cur);
            }
    cout << ans;
    return 0;
}