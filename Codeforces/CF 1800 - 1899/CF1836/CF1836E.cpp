#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

void solve() {
    int k, n;
    cin >> k;
    n = 1 << (k + 1);
    int a[n + 1], p[n + 1];
    p[0] = 0;
    vector<int> v, w;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] ^ a[i];
        if (a[i] == 0)
            v.push_back(i);
        if (p[i] == 0)
            w.push_back(i);
    }
    if (v.size() > 1) {
        cout << v[0] << " " << v[0] << " " << v[1] << " " << v[1] << "\n";
        return;
    }
    if (w.size() > 1) {
        cout << "1 " << w[0] << " " << w[0] + 1 << " " << w[1] << "\n";
        return;
    }
    vector<int> basis(k * 2);
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0)
            continue;
        int cur = a[i];
        for (int j = 0; j < k * 2; ++j) {
            if ((cur & 1 << j) == 0)
                continue;
            if (!basis[j]) {
                basis[j] = cur;
                cur = -1;
                break;
            }
            cur ^= basis[j];
        }
        if (cur != -1) {
            cout << i << " " << i << " ";
            map<int, int> m;
            for (int j = 1; j < i; ++j) {
                if (p[j] == a[i]) {
                    cout << "1 " << j << "!\n";
                    return;
                }
                if (m[p[j] ^ a[i]]) {
                    cout << m[p[j] ^ a[i]] + 1 << " " << j << "!!\n";
                    return;
                }
                m[p[j]] = j;
            }
            cout << "wtf\n";
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}