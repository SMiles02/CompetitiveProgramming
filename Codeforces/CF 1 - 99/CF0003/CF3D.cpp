#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = s.size(), cur = 0, x, y;
    long long ans = 0;
    priority_queue<array<int, 2>> pq;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(')
            ++cur;
        else if (s[i] == ')')
            --cur;
        else {
            cin >> x >> y;
            --cur;
            ans += y;
            pq.push({y - x, i});
            s[i] = ')';
        }
        if (!pq.empty() && cur < 0) {
            cur += 2;
            ans -= pq.top()[0];
            s[pq.top()[1]] = '(';
            pq.pop();
        }
        if (cur < 0) {
            cout << "-1\n";
            return 0;
        }
    }
    if (cur == 0)
        cout << ans << "\n" << s;
    else
        cout << "-1\n";
    return 0;
}