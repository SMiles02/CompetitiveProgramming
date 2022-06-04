#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v = {1};
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1])
            v.push_back(0);
        ++v.back();
    }
    cout << v[v.size() / 2] << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}