// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int hsb(int n) {
    for (int i = 29; i >= 0; --i)
        if ((1 << i) & n)
            return i;
}

int k, h;
vector<int> ans;

void solve(vector<array<int, 2>> a) {
    int ans = 0;
    bool added = 0;
    vector<vector<array<int, 2>>> v(30);
    for (auto i : a) {
        if (i[0] == 0) {
            if (!added) {
                ans.push_back(i[1]);
                added = 1;
            }
        }
        else
            v[hsb(i)].push_back(i);
    }
    for (int i = 0; i < h; ++i)
        ans = max(ans, min(1, v[i].size()));
    if (!v[h].empty())

    for (int i = h + 1; i < 30; ++i) {
        if (v[i].size() < 2)
            for (int j : v[i]) {
                added = 1;
                ans.push_back(j);
            }
        else {

        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n >> k;
    if (k == 0) {
        cout << n << "\n";
        for (int i = 1; i <= n; ++i)
            cout << i << " ";
        return;
    }
    h = hsb(k);
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = i + 1;
    }
    sort(a.begin(), a.end());
    solve(a);
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i << " ";
    return 0;
}