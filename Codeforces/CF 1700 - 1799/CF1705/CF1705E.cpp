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

const int N = 3e5;
int cnt[N], a[N];
priority_queue<int> pq;

void add_element(int i, int x) {
    a[i] = x;
    ++cnt[x];
    pq.push(x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, k, l, m, cur, ans;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> l;
        add_element(i, l);
    }
    while (q--) {
        cin >> k >> l;
        --cnt[a[k]];
        add_element(k, l);
        while (cnt[pq.top()] == 0)
            pq.pop();
        ans = m = pq.top();
        cur = 0;
        for (int i = max(m - 40, 1); i < m + 40; ++i) {
            cur /= 2;
            cur += cnt[i];
            if (cur > 0)
                ans = max(ans, i);
        }
        cout << ans << "\n";
    }
    return 0;
}