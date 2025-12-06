#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    set<array<int, 2>> s;
    map<int, int> cnt;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        int y = ++cnt[v[i]];
        if (y > 0) {
            s.erase({-y + 1, v[i]});
        }
        s.insert({-y, v[i]});
        if (i >= k - 1) {
            cout << (*s.begin())[1] << " ";
            y = --cnt[v[i - k + 1]];
            s.erase({-y - 1, v[i - k + 1]});
            if (y > 0) {
                s.insert({-y, v[i - k + 1]});
            }
        }
    }
    return 0;
}