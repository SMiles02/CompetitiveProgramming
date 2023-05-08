#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, mx = 0;
    long long s = 0;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        ++m[k];
        s += k;
        mx = max(mx, m[k]);
    }
    if (mx > 2)
        cout << "cslnb";
    else if (mx == 2) {
        int cnt = 0, val;
        for (auto i : m)
            if (i.second == 2) {
                ++cnt;
                val = i.first;
            }
        if (cnt > 1 || m[val - 1] > 0 || m[0] > 1 || (s - ((1LL * n * (n - 1)) / 2)) % 2 == 0)
            cout << "cslnb";
        else
            cout << "sjfnb";
    }
    else if ((s - ((1LL * n * (n - 1)) / 2)) & 1)
        cout << "sjfnb";
    else
        cout << "cslnb";
    return 0;
}