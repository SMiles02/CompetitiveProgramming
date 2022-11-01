#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < n * 2; i += 2)
        if (s[i] != s[i + 1]) {
            if ((s[i] - '0') == v.size() % 2)
                v.push_back(i + 1);
            else
                v.push_back(i + 2);
        }
    if (v.size() & 1) {
        cout << "-1\n";
        return;
    }
    cout << v.size() << "\n";
    for (int i : v)
        cout << i << " ";
    cout << "\n";
    for (int i = 1; i <= n * 2; i += 2)
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