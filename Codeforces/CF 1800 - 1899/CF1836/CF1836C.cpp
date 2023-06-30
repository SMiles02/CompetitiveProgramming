#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> v = {0, 1};

void print_sum(int a, int b) {
    cout << a << " + " << b << " = " << a + b << "\n";
}

void solve() {
    int a, b, c;
    ll k;
    cin >> a >> b >> c >> k;
    if (c < max(a, b) || max(a, b) + 1 < c) {
        cout << "-1\n";
        return;
    }
    ll done = 0;
    array<int, 2> s;
    for (int i = v[a]; i < v[a + 1]; ++i) {
        int l = max(v[c] - i, v[b]), r = min(v[c] * 10 - 1 - i, v[b] * 10 - 1);
        if (l <= r) {
            if (done + r - l + 1 >= k) {
                print_sum(i, l + k - done - 1);
                return;
            }
            done += r - l + 1;
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while (v.size() < 9)
        v.push_back(v.back() * 10);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}