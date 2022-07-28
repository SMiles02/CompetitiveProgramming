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

const int N = 2e5 + 1;
vector<array<int, 2>> a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, p, e, x, y, ans = 0, k;
    bool exact_same = false, cur_diff;
    cin >> n;
    map<int, vector<int>> v;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        while (m--) {
            cin >> p >> e;
            v[p].push_back(e);
            a[i].push_back({p, e});
            s.insert(p);
        }
    }
    for (int i : s) {
        v[i].push_back(0);
        sort(v[i].begin(), v[i].end());
    }
    for (int i = 0; i < n; ++i) {
        cur_diff = false;
        for (auto j : a[i]) {
            k = v[j[0]].size();
            // cout << j[0] << ": ";
            // for (auto _ : v[j[0]])
            //     cout << _ << " ";
            // cout << "!\n";
            // cout << j[1] << " " << v[j[0]][k - 1] << "\n";
            // cout << (j[1] == v[j[0]][k - 1]) << "\n";
            // return 0;
            if (j[1] == v[j[0]][k - 1] && v[j[0]][k - 1] != v[j[0]][k - 2])
                cur_diff = true;
        }
        // cout << cur_diff << "!\n";
        ans += cur_diff;
        if (!cur_diff)
            exact_same = true;
    }
    cout << ans + exact_same;
    return 0;
}