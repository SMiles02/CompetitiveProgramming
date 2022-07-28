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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s, t;
    cin >> s;
    cin >> t;
    vector<pair<char, int>> v = {{'?', 0}}, w = {{'?', 0}};
    for (auto i : s) {
        if (i != v.back().first)
            v.push_back({i, 1});
        else
            ++v.back().second;
    }
    for (auto i : t) {
        if (i != w.back().first)
            w.push_back({i, 1});
        else
            ++w.back().second;
    }
    if (v.size() != w.size()) {
        cout << "No";
        return 0;
    }
    bool ok = true;
    for (int i = 0; i < v.size(); ++i)
        if (v[i].first != w[i].first || v[i].second > w[i].second || (v[i].second < w[i].second && v[i].second == 1))
            ok = false;
    if (ok)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}