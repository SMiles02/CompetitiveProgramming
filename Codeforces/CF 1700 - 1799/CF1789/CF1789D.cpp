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

void left_shift(vector<int> &v, int k) {
    for (int i = 0; i + k < v.size(); ++i)
        v[i] ^= v[i + k];
}

void right_shift(vector<int> &v, int k) {
    for (int i = v.size() - 1; i - k >= 0; --i)
        v[i] ^= v[i - k];
}

void bit_shift(vector<int> &v, int k) {
    if (k < 0)
        right_shift(v, abs(k));
    else if (k > 0)
        left_shift(v, k);
}

void print_vector(vector<int> &v) {
    for (auto i : v)
        cout << i;
    cout << "\n";
}

void solve() {
    int n, x = 0, y = 0, s, t;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1') {
            ++x;
            s = i;
        }
        v[i] = a[i] - '0';
    }
    for (int i = 0; i < n; ++i) {
        if (b[i] == '1') {
            ++y;
            t = i;
        }
        w[i] = b[i] - '0';
    }
    if (y == 0) {
        if (x == 0)
            cout << "0\n";
        else
            cout << "-1\n";
        return;
    }
    if (x == 0) {
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    if (s < t) {
        bit_shift(v, s - t);
        ans.push_back(s - t);
        s = t;
    }
    for (int i = s - 1; i >= 0; --i)
        if (v[i] != w[i]) {
            bit_shift(v, s - i);
            ans.push_back(s - i);
        }
    int k = -1;
    for (int i = 0; i <= s; ++i)
        if (v[i] == 1) {
            k = i;
            break;
        }
    for (int i = s; i < n; ++i)
        if (v[i] != w[i]) {
            bit_shift(v, k - i);
            ans.push_back(k - i);
        }
    // print_vector(v);
    assert(ans.size() <= n);
    cout << ans.size() << "\n";
    if (ans.empty())
        return;
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}