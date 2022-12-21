#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 20;
int a[N][2], mx, n;
ll mini = 1e9;
vector<vector<int>> ans;

void solve(int out, vector<int> v) {
    if (out > mx) {
        ll s = 0;
        for (int i = 0; i < v.size(); ++i) {
            s += a[v[i]][1];
            if (i + 1 < v.size())
                s -= a[v[i]][0];
        }
        if (mini > s) {
            ans.clear();
            mini = s;
        }
        if (mini == s)
            ans.push_back(v);
        return;
    }
    for (int i = 1; i <= n; ++i)
        if (out <= a[i][1]) {
            v.push_back(i);
            solve(a[i][0], v);
            v.pop_back();
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i][0] >> a[i][1];
        mx = max(mx, a[i][1]);
    }
    solve(0, {});
    cout << mini << " " << ans.size() << "\n";
    for (auto i : ans) {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
    return 0;
}