#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    set<int> s;
    vector<int> v(n), cnt(k + 1);
    for (int i = 0; i <= k; ++i) {
        s.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (++cnt[min(v[i], k)] == 1) {
            s.erase(min(v[i], k));
        }
        if (i + 1 >= k) {
            cout << *s.begin() << " ";
            if (--cnt[min(v[i - k + 1], k)] == 0) {
                s.insert(min(v[i - k + 1], k));
            }
        }
    }
    return 0;
}