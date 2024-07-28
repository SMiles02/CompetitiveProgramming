#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    if (n == 1) {
        cout << "1\n";
        ans = {1};
    }
    else if (n == 2) {
        cout << "2\n";
        ans = {1, 2};
    }
    else if (n == 3) {
        cout << "2\n";
        ans = {1, 2, 2};
    }
    else if (n == 4) {
        cout << "3\n";
        ans = {1, 2, 2, 3};
    }
    else if (n == 5) {
        cout << "3\n";
        ans = {1, 2, 2, 3, 3};
    }
    else if (n == 6) {
        cout << "4\n";
        ans = {1, 2, 2, 3, 3, 4};
    }
    else {
        cout << "4\n";
        for (int i = 1; i <= n; ++i) {
            if (i % 4 == 0) {
                ans.push_back(4);
            }
            else {
                ans.push_back(i % 4);
            }
        }
    }
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}