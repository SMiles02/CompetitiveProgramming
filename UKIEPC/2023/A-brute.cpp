#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, w, cnt_done = 0;
    cin >> n >> w;
    vector<array<int, 2>> a(n);
    set<array<int, 2>> s;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i] = {abs(x - w), y};
    }
    vector<bool> done(n);
    while (cnt_done > 0)
    return 0;
}