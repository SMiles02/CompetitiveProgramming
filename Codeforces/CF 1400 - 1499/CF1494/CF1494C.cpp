#include <bits/stdc++.h>
using namespace std;

int solve_case(deque<int> a, deque<int> b) {
    if (a.empty())
        return 0;
    while (!b.empty() && b[0] < a[0])
        b.pop_front();
    if (b.empty())
        return 0;
    set<int> s;
    for (int i : b)
        s.insert(i);
    int n = a.size(), right_point = 0, ans = 0, l, r, m;
    vector<int> p(n + 1);
    for (int i = n - 1; i >= 0; --i)
        p[i] = p[i + 1] + s.count(a[i]);
    for (int i = 0; i < b.size(); ++i) {
        while (right_point + 1 < n && a[right_point + 1] <= b[i] + right_point + 1)
            ++right_point;
        l = i;
        r = b.size() - 1;
        while (l < r) {
            m = l + (r - l) / 2 + 1;
            if (b[i] + right_point < b[m])
                r = m - 1;
            else
                l = m;
        }
        ans = max(ans, l - i + 1 + p[right_point + 1]);
    }
    return ans;
}

void solve() {
    int n, m, k;
    deque<int> a, b, c, d;
    cin >> n >> m;
    while (n--) {
        cin >> k;
        if (k < 0)
            a.push_front(-k);
        else
            b.push_back(k);
    }
    while (m--) {
        cin >> k;
        if (k < 0)
            c.push_front(-k);
        else
            d.push_back(k);
    }
    cout << solve_case(a, c) + solve_case(b, d) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}