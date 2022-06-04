#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, o = 0, t = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    vector<int> v = {1};
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1])
            v.push_back(0);
        ++v.back();
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 1)
            ++o;
        else
            ++t;
    }
    if (o) {
        --o;
        ++t;
    }
    cout << t + o / 2 << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}