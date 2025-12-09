#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fix(multiset<int>& used, multiset<int>& unused, int& max_size, ll& cur) {
    while (used.size() < max_size && !unused.empty()) {
        cur += *(--unused.end());
        used.insert(*(--unused.end()));
        unused.erase(--unused.end());
    }
    while (used.size() > max_size) {
        cur -= *used.begin();
        unused.insert(*used.begin());
        used.erase(used.begin());
    }
    while (!used.empty() && !unused.empty() && (*used.begin()) < (*(--unused.end()))) {
        cur += *(--unused.end()) - *used.begin();
        used.insert(*(--unused.end()));
        unused.insert(*used.begin());
        used.erase(used.begin());
        unused.erase(--unused.end());
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, a, b;
    ll ans = 0, cur = 0;
    cin >> a >> b >> n;
    multiset<int> a_used, a_unused, b_used, b_unused;
    array<int, 3> x[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i][1] >> x[i][2];
        x[i][0] = x[i][2] - x[i][1];
        cur += x[i][2];
        b_used.insert(x[i][2]);
    }
    fix(b_used, b_unused, b, cur);
    ans = cur;
    sort(x, x + n);
    for (int i = 0; i < n; ++i) {
        a_unused.insert(x[i][1]);
        if (b_unused.find(x[i][2]) != b_unused.end())
            b_unused.erase(b_unused.find(x[i][2]));
        else {
            cur -= x[i][2];
            b_used.erase(b_used.find(x[i][2]));
        }
        fix(a_used, a_unused, a, cur);
        fix(b_used, b_unused, b, cur);
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}