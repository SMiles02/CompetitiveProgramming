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

const int N = (1 << 17);
int trie[N * 18 + 69][2], cur;
vector<int> v;

void insert(int x, int i, int j) {
    if (j == -1)
        return;
    // cout << x << " " << i << " " << j << "\n";
    bool b = x & (1 << j);
    if (!trie[i][b]) {
        trie[i][b] = ++cur;
        v.push_back(cur);
    }
    insert(x, trie[i][b], j - 1);
}

int find_min(int x) {
    int tmp = 1, ans = 0;
    for (int i = 16; i >= 0; --i) {
        bool b = x & (1 << i);
        bool c = b;
        if (trie[tmp][c]) {
            tmp = trie[tmp][c];
            ans += (1 << i) * c;
        }
        else {
            tmp = trie[tmp][1 - c];
            ans += (1 << i) * (1 - c);
        }
    }
    return (ans ^ x);
}

int find_max(int x) {
    int tmp = 1, ans = 0;
    for (int i = 16; i >= 0; --i) {
        bool b = x & (1 << i);
        bool c = !b;
        if (trie[tmp][c]) {
            tmp = trie[tmp][c];
            ans += (1 << i) * c;
        }
        else {
            tmp = trie[tmp][1 - c];
            ans += (1 << i) * (1 - c);
        }
    }
    return (ans ^ x);
}

void solve() {
    while (!v.empty()) {
        trie[v.back()][0] = trie[v.back()][1] = 0;
        v.pop_back();
    }
    cur = 1;
    v.push_back(1);
    int l, r, x;
    cin >> l >> r;
    for (int i = l; i <= r; ++i) {
        cin >> x;
        insert(x, 1, 16);
    }
    for (int i = l; i <= r; ++i)
        if (find_min(i ^ x) == l && find_max(i ^ x) == r) {
            cout << (i ^ x) << "\n";
            return;
        }
    cout << "fuck me\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}