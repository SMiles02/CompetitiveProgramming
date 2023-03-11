#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9 + 5;
int n;
vector<int> pf;

vector<int> get_factors(int m) {
    int m1 = m;
    vector<int> v = {1, m};
    for (int i = 2; i * i <= m; ++i)
        if (m % i == 0) {
            v.push_back(i);
            if (i * i != m)
                v.push_back(m / i);
            pf.push_back(i);
            while (m1 % i == 0)
                m1 /= i;
        }
    pf.push_back(m1);
    return v;
}

void solve() {
    int m1, m2, ans = 0, xr = 0;
    cin >> n >> m1 >> m2;
    pf.clear();
    vector<int> v = get_factors(m1), w = get_factors(m2);
    map<ll, int> big;
    set<ll> s;
    for (int i : v)
        for (int j : w)
            s.insert(1LL * i * j);
    for (auto i : s) {
        if (i <= n)
            big[i] = i;
        else {
            int tmp = 0;
            for (int j : pf)
                if (i % j == 0)
                    tmp = max(tmp, big[i / j]);
            big[i] = tmp;
        }
        if (i / big[i] <= n) {
            ++ans;
            xr ^= i / big[i];
        }
    }
    cout << ans << " " << xr << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}