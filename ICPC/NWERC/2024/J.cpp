#include <bits/stdc++.h>
using namespace std;

int sq(int x) {
    return x * x;
}

int dist(int a, int b, int c, int d) {
    return sqrt(sq(a - c) + sq(b - d));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int, 4>> a(n);
    vector<array<int, 2>> ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][1] >> a[i][2] >> a[i][0];
        a[i][3] = i;
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; ++i) {
        ans[i][0] = a[i][3];
        ans[i][1] = a[i][0];
        for (int j = 0; j < i; ++j) {
            ans[i][1] = min(ans[i][1], dist(a[i][1], a[i][2], a[j][1], a[j][2]));
        }
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) {
        cout << i[1] << "\n";
    }
    return 0;
}