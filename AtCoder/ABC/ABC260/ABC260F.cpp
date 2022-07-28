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

const int S = 3e5 + 5, T = 3005;
vector<int> e[S];
int con[T][T];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int s, t, m, x, y;
    cin >> s >> t >> m;
    while (m--) {
        cin >> x >> y;
        e[x].push_back(y);
    }
    for (int i = 1; i <= s; ++i) {
        sort(e[i].begin(), e[i].end());
        for (int k = 0; k < e[i].size(); ++k)
            for (int j = 0; j < k; ++j) {
                if (con[e[i][j] - s][e[i][k] - s]) {
                    cout << i << " " << e[i][j] << " " << con[e[i][j] - s][e[i][k] - s] << " " << e[i][k] << "\n";
                    return 0;
                }
                con[e[i][j] - s][e[i][k] - s] = i;
            }
    }
    cout << -1;
    return 0;
}