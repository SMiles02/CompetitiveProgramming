#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, ans = 0, done = 0;
    cin >> n;
    vector<int> cd(n + 1);
    priority_queue<int> p, q;
    for (int i = 2; i <= n; ++i) {
        cin >> x;
        ++cd[x];
    }
    cd[0] = 1;
    sort(cd.begin(), cd.end());
    while (done < n) {
        ++ans;
        while (!p.empty()) {
            x = p.top();
            p.pop();
            ++done;
            if (--x > 0)
                q.push(x);
        }
        swap(p, q);
        if (!cd.empty() && cd.back() > 0) {
            ++done;
            if (--cd.back() > 0)
                p.push(cd.back());
            cd.pop_back();
        }
        else if (!p.empty()) {
            x = p.top();
            p.pop();
            ++done;
            if (--x > 0)
                p.push(x);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}