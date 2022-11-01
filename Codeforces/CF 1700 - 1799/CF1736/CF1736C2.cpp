#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9;

ll f(int x) {
    return (1LL * x * (x + 1)) / 2;
}

ll f(int l, int r) {
    return f(r) - f(l - 1);
}

struct BIT {
    int n;
    ll rtn;
    vector<ll> bit;
    BIT(int n) : n(n), bit(n+1,0) {}
    void update(int x, int d) { for (int i=x;i<=n;i+=i&-i) bit[i]+=d; }
    ll query(int x) {
        rtn=0;
        for (int i=x;i;i-=i&-i) rtn+=bit[i];
        return rtn;
    }
    ll query(int x, int y) { return query(y) - query(x-1); }
};


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, t, x, y, l, r, m, lp, rp;
    cin >> n;
    int a[n + 1], b[n + 1][2];
    array<int, 2> tmp;
    priority_queue<array<int, 2>> q;
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> p;
    BIT bit(n), bit2(n);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    q.push({n + 1, -INF});
    q.push({n + 2, -INF});
    ll pos = 0, neg = 0;
    for (int i = n; i >= 1; --i) {
        while (!p.empty() && p.top()[0] < 1 - i) {
            // cout << "rem " << p.top()[1] << " " << p.top()[0] << " " << 1 - i << "\n";
            q.push({p.top()[1], p.top()[0]});
            p.pop();
        }
        while (q.size() > 2)
            q.pop();
        tmp = q.top();
        q.pop();
        b[i][0] = q.top()[0]; // actual blockage
        b[i][1] = tmp[0]; // next blockage
        bit.update(i, b[i][1] - b[i][0]);
        bit2.update(i, b[i][0] - i);
        pos += b[i][0];
        neg += i;
        q.push(tmp);
        p.push({a[i] - i, i});
    }
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (a[x] <= y) {
            if (x == 1) {
                cout << pos - neg << "\n";
                continue;
            }
            l = 1;
            r = x - 1;
            while (l < r) {
                m = l + (r - l) / 2;
                if (b[m][0] < x)
                    l = m + 1;
                else
                    r = m;
            }
            if (b[l][0] != x) {
                cout << pos - neg << "\n";
                continue;
            }
            lp = l;
            r = x - 1;
            while (l < r) {
                m = l + (r - l) / 2 + 1;
                if (b[m][0] == x)
                    l = m;
                else
                    r = m - 1;
            }
            rp = l;
            if (1 - rp > y - x) {
                cout << pos - neg << "\n";
                continue;
            }
            l = lp;
            r = rp;
            while (l < r) {
                m = l + (r - l) / 2;
                if (1 - m <= y - x)
                    r = m;
                else
                    l = m + 1;
            }
            cout << pos - neg + bit.query(l, rp) << "\n";
        }
        else {
            if (x == 1) {
                cout << pos - neg << "\n";
                continue;
            }
            l = 1;
            r = x - 1;
            while (l < r) {
                m = l + (r - l) / 2;
                if (b[m][0] >= x)
                    r = m;
                else
                    l = m + 1;
            }
            lp = l;
            rp = x - 1;
            if (1 - lp <= y - x) {
                cout << pos - neg << "\n";
                continue;
            }
            if (1 - rp > y - x) {
                cout << pos - neg - bit2.query(lp, rp) + 1LL * x * (rp - lp + 1) - f(lp, rp) << "\n";
                continue;
            }
            l = lp;
            r = rp;
            while (l < r) {
                m = l + (r - l) / 2 + 1;
                if (1 - m <= y - x)
                    r = m - 1;
                else
                    l = m;
            }
            cout << pos - neg - bit2.query(lp, l) + 1LL * x * (l - lp + 1) - f(lp, l) << "\n";
        }
    }
    return 0;
}