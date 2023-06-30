#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int l, int r) { // get beauty of [l, r]
    vector<int> x, y;
    for (int i = l; i <= r; ++i) {
        x.push_back(v[i]);
        y.push_back(v[i]);
    }
    sort(y.begin(), y.end());
    int ans = 0;
    for (int i = 0; i < x.size(); ++i) {
        int j = i;
        set<int> s, t;
        s.insert(x[i]);
        t.insert(y[i]);
        while (s != t) {
            ++j;
            s.insert(x[j]);
            t.insert(y[j]);
        }
        ans += j - i;
        i = j;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    long long tot_ans = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    for (int r = 0; r < n; ++r) {
        int ans = 0;
        for (int l = 0; l <= r; ++l)
            ans += solve(v, l, r);
        cout << ans << "\n";
        tot_ans += ans;
    }
    cerr << tot_ans << "\n";
    return 0;
}