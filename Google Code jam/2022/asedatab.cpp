#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool local = 1;
string s;
int c, qM;
vector<int> v[9];

bool query(int x) {
    ++qM;
    string tmp = "";
    for (int i = 0; i < 8; ++i) {
        if ((1 << i) & x)
            tmp += "1";
        else
            tmp += "0";
    }
    cout << tmp << endl;
    if (local) {
        for (int i = 0; i < 8; ++i) {
            if (s[i] == tmp[i])
                s[i] = '0';
            else
                s[i] = '1';
        }
        c = 0;
        for (int i = 0; i < 8; ++i)
            c += (s[i] == '1');
        if (qM == 300 && c != 0)
            c = -1;
        cout << "New: " << s << endl;
        cout << "Ans: " << c << endl;
    }
    else
        cin >> c;
    return (c == 0 || c == -1);
}

bool genNumber(int x) {
    return query(v[x][uniform_int_distribution<int>(0, sz(v[x]) - 1)(rng)]);
}

void solve() {
    qM = 0;
    if (local) {
        s = "";
        for (int i = 0; i < 8; ++i) {
            if (uniform_int_distribution<int>(0, 1)(rng))
                s += "1";
            else
                s += "0";
        }
        // cin >> s;
    }
    if (query(69))
        return;
    for (int i = 1; i < 300; ++i) {
        if (genNumber(c))
            return;
    }
}

int main() {
    for (int i = 0; i < 256; ++i)
        v[__builtin_popcount(i)].push_back(i);
    int t, mx = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
        if (local) {
            mx = max(mx, qM);
            // cerr << qM << " " << c << endl;
        }
        if (c == -1)
            return 0;
    }
    if (local)
        cerr << "Finished. Max: " << mx << endl;
    return 0;
}