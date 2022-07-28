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
    int n, cur = 0;
    cin >> n;
    string s;
    cin >> s;
    int a[n];
    deque<int> v[2];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v[s[i] - '0'].push_back(a[i]);
    }
    sort(v[0].rbegin(), v[0].rend());
    sort(v[1].rbegin(), v[1].rend());
    int ans = max(v[0].size(), v[1].size());
    while (!v[1].empty()) {
        while (!v[0].empty() && v[0].front() >= v[1].front())
            v[0].pop_front();
        ++cur;
        // cout << v[1].front() << " " << (int)v[0].size() + cur << "\n";
        ans = max(ans, (int)v[0].size() + cur);
        v[1].pop_front();
    }
    cout << ans;
    return 0;
}