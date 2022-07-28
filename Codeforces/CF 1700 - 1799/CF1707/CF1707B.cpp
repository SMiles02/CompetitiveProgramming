#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt1, cnt2;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
        ++cnt1[a[i] - a[i - 1]];
    while (cnt1.size() > 1) {
        cnt2.clear();
        int last = -1;
        for (auto i : cnt1) {
            if (last != -1)
                ++cnt2[i.first - last];
            last = i.first;
            if (i.second > 1)
                cnt2[0] += i.second - 1;
        }
        swap(cnt1, cnt2);
    }
    if (cnt1.begin()->second > 1)
        cout << "0\n";
    else
        cout << cnt1.begin()->first << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}