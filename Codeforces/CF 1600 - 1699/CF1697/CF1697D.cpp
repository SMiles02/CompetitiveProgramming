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

const int N = 1001, L = 26;
bool local = 1;
set<int> exists[L];
string s(N, '?'), inp;

char query_pos(int x) {
    cout << "? 1 " << x << endl;
    char c;
    if (local) {
        c = inp[x];
        cout << c << endl;
    }
    else
        cin >> c;
    return c;
}

int query_range(int l, int r) {
    cout << "? 2 " << l << " " << r << endl;
    int ret;
    if (local) {
        set<char> st;
        for (int i = l; i <= r; ++i)
            st.insert(inp[i]);
        ret = st.size();
        cout << ret << endl;
    }
    else
        cin >> ret;
    return ret;
}

void set_char(int x, char c) {
    s[x] = c;
    exists[c - 'a'].insert(x);
}

int count_unique(int l, int r) {
    int ret = 0;
    for (int i = 0; i < L; ++i)
        ret += (exists[i].lower_bound(l) != exists[i].end() && *exists[i].lower_bound(l) <= r);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, cnt = 0, tot, l, r, m;
    if (local) {
        cin >> inp;
        n = inp.size();
        inp = "?" + inp;
    }
    else
        cin >> n;
    tot = query_range(1, n);
    set_char(1, query_pos(1));
    set<pair<int, char>> t;
    for (int i = 2; i <= tot; ++i) {
        l = i;
        r = n;
        while (l < r) {
            m = l + (r - l) / 2;
            if (query_range(1, m) < i)
                l = m + 1;
            else
                r = m;
        }
        set_char(l, query_pos(l));
    }
    for (int i = 1; i <= n; ++i) {
        if (s[i] != '?') {
            ++cnt;
            t.insert({i, s[i]});
        }
        else {
            // cout << i << "!!!!\n";
            vector<pair<int, char>> v;
            for (auto j : t)
                v.push_back(j);
            l = 0;
            r = cnt - 1;
            while (l < r) {
                m = l + (r - l) / 2 + 1;
                if (query_range(v[m].first, i) == cnt - m)
                    l = m;
                else
                    r = m - 1;
            }
            s[i] = v[l].second;
            t.erase({v[l].first, v[l].second});
            t.insert({i, v[l].second});
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; ++i)
        cout << s[i];
    cout << endl;
    return 0;
}