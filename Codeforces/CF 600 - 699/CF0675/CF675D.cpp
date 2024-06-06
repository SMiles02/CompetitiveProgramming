#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n;
    set<array<int, 2>> s;
    cin >> k;
    s.insert({k, 0});
    for (int i = 1; i < n; ++i) {
        cin >> k;
        int p = -1, d = -1;
        if ((*s.begin())[0] < k) {
            p = (*--s.lower_bound({k, 0}))[0];
            d = (*--s.lower_bound({k, 0}))[1];
        }
        if (s.upper_bound({k, 0}) != s.end() && (*s.upper_bound({k, 0}))[1] > d) {
            p = (*s.upper_bound({k, 0}))[0];
            d = (*s.upper_bound({k, 0}))[1];
        }
        cout << p << " ";
        s.insert({k, d + 1});
    }
    return 0;
}