#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> pt, rk;
    DSU(int n) : pt(n + 1), rk(n + 1, 1) {
        for (int i = 0; i <= n; ++i)
            pt[i] = i;
    }
    int find_set(int i) {
        return i == pt[i] ? i : pt[i] = find_set(pt[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    DSU dsu(26);
    set<char> st;
    vector<char> before(26, '?');
    for (char i = 'a'; i <= 'z'; ++i)
        st.insert(i);
    for (auto i : s) {
        if (before[i - 'a'] == '?')
            for (auto j : st)
                if (!dsu.connected(i - 'a', j - 'a') || dsu.rk[dsu.find_set(0)] == 26) {
                    dsu.unite(i - 'a', j - 'a');
                    before[i - 'a'] = j;
                    st.erase(j);
                    break;
                }
        cout << before[i - 'a'];
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