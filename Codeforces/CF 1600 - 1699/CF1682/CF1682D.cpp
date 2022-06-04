#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x = 0;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v, w, heads;
    vector<array<int, 2>> ans;

    for (int i = 0; i < n; ++i)
        if (s[i] == '1')
            v.push_back(i + 1);
    x = v.size();
    if ((x & 1) || x == 0) {
        cout << "NO\n";
        return;
    }

    // filling in the bits between chain ends
    for (int i = v[0] + 1; i < v[1]; ++i)
        ans.push_back({i - 1, i});

    // merging all 1...00000...1 into a single node
    // with all nodes requiring even more degree
    for (int i = 2; i < x; i += 2) {
        for (int j = v[i] + 1; j <= v[i + 1]; ++j) {
            s[j - 1] = '1';
            ans.push_back({j - 1, j});
        }
        heads.push_back(v[i]);
    }

    // unmatched 0s
    for (int i = 1; i <= n; ++i)
        if (s[i - 1] == '0' && !(v[0] <= i && i <= v[1]))
            heads.push_back(i);

    sort(heads.begin(), heads.end());

    // start of chain
    w.push_back(v[1]);

    // middle bits
    for (int i : heads)
        if (i > v[1])
            w.push_back(i);
    for (int i : heads)
        if (i < v[0])
            w.push_back(i);

    // end of chain
    w.push_back(v[1] - 1);
    
    // creating the line tree
    for (int i = 1; i < w.size(); ++i)
        ans.push_back({w[i - 1], w[i]});

    cout << "YES\n";
    for (auto i : ans)
        cout << i[0] << " " << i[1] << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}