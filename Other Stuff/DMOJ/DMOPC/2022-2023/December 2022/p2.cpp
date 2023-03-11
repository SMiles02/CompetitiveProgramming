#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, s, k;
    cin >> n >> q;
    int p[n];
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    while (q--) {
        cin >> s;
        deque<int> d;
        while (s--) {
            cin >> k;
            d.push_back(k - 1);
        }
        sort(d.begin(), d.end());
        if (d.size() == 1) {
            cout << "1\n";
            continue;
        }
        while ((d[0] + 1) % n == d[1]) {
            d.push_back(d[0]);
            d.pop_front();
        }
        d.push_back(d[0]);
        d.pop_front();
        int ans = 1;
        for (int i = 1; i < d.size(); ++i)
            ans += ((d[i - 1] + 1) % n != d[i]);
        cout << ans << "\n";
    }
    return 0;
}