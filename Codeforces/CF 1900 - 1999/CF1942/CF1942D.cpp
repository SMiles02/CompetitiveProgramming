#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;

const int N = 1005, INF = -1e9 - 1;
int a[N][N], k;
vector<int> dp[N];

vector<int> take_max(vector<int>& v, vector<int>& w) {
    vector<int> ans;
    int i = 0, j = 0;
    while (i < v.size() && j < w.size() && ans.size() < k) {
        if (v[i] > w[j]) {
            ans.push_back(v[i++]);
        }
        else {
            ans.push_back(w[j++]);
        }
    }
    while (i < v.size() && ans.size() < k) {
        ans.push_back(v[i++]);
    }
    while (j < w.size() && ans.size() < k) {
        ans.push_back(w[j++]);
    }
    return ans;
}

vector<int> take_max(vector<int>& v, vector<int>& w, int x) {
    vector<int> ans;
    int i = 0, j = 0;
    while (i < v.size() && j < w.size() && ans.size() < k) {
        if (v[i] > w[j] + x) {
            ans.push_back(v[i++]);
        }
        else {
            ans.push_back(w[j++] + x);
        }
    }
    while (i < v.size() && ans.size() < k) {
        ans.push_back(v[i++]);
    }
    while (j < w.size() && ans.size() < k) {
        ans.push_back(w[j++] + x);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    dp[0] = {0};
    dp[1] = {0, a[1][1]};
    sort(dp[1].rbegin(), dp[1].rend());
    for (int i = 2; i <= n; ++i) {
        dp[i] = {a[1][i]};
        for (int x = 2; x <= i; ++x) {
            dp[i] = take_max(dp[i], dp[x - 2], a[x][i]);
        }
        dp[i] = take_max(dp[i], dp[i - 1]);
    }
    for (int i = 0; i < k; ++i) {
        cout << dp[n][i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = INF;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}