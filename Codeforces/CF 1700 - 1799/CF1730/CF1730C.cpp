#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size(), k;
    vector<int> ok, v;
    for (auto i : s) {
        k = (i - '0');
        while (!ok.empty() && ok.back() > k) {
            v.push_back(min(ok.back() + 1, 9));
            ok.pop_back();
        }
        ok.push_back(k);
    }
    sort(v.rbegin(), v.rend());
    for (int i : ok) {
        while (!v.empty() && v.back() < i) {
            cout << v.back();
            v.pop_back();
        }
        cout << i;
    }
    while (!v.empty()) {
        cout << v.back();
        v.pop_back();
    }
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