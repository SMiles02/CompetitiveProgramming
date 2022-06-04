#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 3000;
int n, a[N];

ll calc(deque<int>& d) {
    for (int i : d)
        cout << i << " ";
    cout << "\n";
    ll mn = 0, mx = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            c += d.front();
            d.pop_front();
        }
        else
            c += a[i];
        mn = min(mn, c);
        mx = max(mx, c);
    }
    cout << mx - mn + 1 << "\n";
    return mx - mn + 1;
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int cnt = 0;
    ll x = 0, l, r, m, o, ans = 1, dmg, L, R, k, blank;
    cin >> n >> k;
    deque<int> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        x += a[i];
        cnt += (a[i] == 0);
    }
    if (!(x - 1LL * k * cnt <= 0 && 0 <= x + 1LL * k * cnt)) {
        cout << "-1\n";
        return 0;
    }
    l = 0;
    r = 1LL * k * cnt;
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        o = 1LL * k * cnt - 1LL * k * ((m + k - 1) / k);
        if (0 <= x - m + o)
            l = m;
        else
            r = m - 1;
    }
    d.clear();
    L = l;
    R = l - x;
    blank = cnt - ((L + k - 1) / k) - ((R + k - 1) / k);
    while (L > 0) {
        d.push_back(-min(L, k));
        L -= min(L, k);
    }
    while (R > 0) {
        d.push_back(min(R, k));
        R -= min(R, k);
    }
    while (blank-- > 0)
        d.push_back(0);
    ans = max(ans, calc(d));
    d.clear();
    L = l;
    R = l - x;
    blank = cnt - ((L + k - 1) / k) - ((R + k - 1) / k);
    while (L > 0) {
        d.push_back(-min(L, k));
        L -= min(L, k);
    }
    while (blank-- > 0)
        d.push_back(0);
    while (R > 0) {
        d.push_back(min(R, k));
        R -= min(R, k);
    }
    ans = max(ans, calc(d));



    l = 0;
    r = 1LL * k * cnt;
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        o = 1LL * k * cnt - 1LL * k * ((m + k - 1) / k);
        if (x + m - o <= 0)
            l = m;
        else
            r = m - 1;
    }
    d.clear();
    L = l;
    R = x + l;
    blank = cnt - ((L + k - 1) / k) - ((R + k - 1) / k);
    while (L > 0) {
        d.push_back(min(L, k));
        L -= min(L, k);
    }
    while (R > 0) {
        d.push_back(-min(R, k));
        R -= min(R, k);
    }
    while (blank-- > 0)
        d.push_back(0);
    ans = max(ans, calc(d));
    d.clear();
    L = l;
    R = x + l;
    blank = cnt - ((L + k - 1) / k) - ((R + k - 1) / k);
    while (L > 0) {
        d.push_back(min(L, k));
        L -= min(L, k);
    }
    while (blank-- > 0)
        d.push_back(0);
    while (R > 0) {
        d.push_back(-min(R, k));
        R -= min(R, k);
    }
    ans = max(ans, calc(d));
    cout << ans << "\n";
    return 0;
}