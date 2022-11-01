#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

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

const int N = 1e6 + 1;
int a[N];

void solve() {
    int n, m, x, y, z, s = 0, t, l, r, mid, t1, t2, t3;
    ll ans = 0, X, Y;
    cin >> n >> m;
    vector<BIT> sm, cnt;
    vector<int> v(3);
    BIT tmp(n);
    sm.push_back(tmp);
    sm.push_back(tmp);
    sm.push_back(tmp);
    cnt.push_back(tmp);
    cnt.push_back(tmp);
    cnt.push_back(tmp);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sm[a[i]].update(i, i);
        cnt[a[i]].update(i, 1);
        s += a[i];
    }
    while (m--) {
        cin >> x >> y >> z;
        sm[a[x]].update(x, -x);
        cnt[a[x]].update(x, -1);
        s -= a[x];
        a[x] = y;
        sm[a[x]].update(x, x);
        cnt[a[x]].update(x, 1);
        s += a[x];
        cerr << s << "\n";
        t = cnt[1].query(z) + cnt[2].query(z) * 2;
        if (s & 1) {
            cerr << "Not even\n";
            --ans;
        }
        else if (t >= s) { // 2 -> 1
            if (min(cnt[2].query(z), cnt[1].query(z + 1, n)) < t - s)
                --ans;
            else {
                t1 = 2;
                t2 = 1;
                t3 = t - s;
                l = 1;
                r = z;
                while (l < r) {
                    mid = l + (r - l) / 2;
                    if (cnt[t1].query(mid, z) > t3)
                        l = mid + 1;
                    else
                        r = mid;
                }
                X = sm[t1].query(l, z);
                l = z + 1;
                r = n;
                while (l < r) {
                    mid = l + (r - l) / 2 + 1;
                    if (cnt[t2].query(z + 1, mid) > t3)
                        r = mid - 1;
                    else
                        l = mid;
                }
                Y = sm[t2].query(z + 1, l);
                ans += Y - X;
                cerr << X << " " << Y << "!\n";
            }
        }
        else { // 1 -> 2
            if (min(cnt[1].query(z), cnt[2].query(z + 1, n)) < s - t)
                --ans;
            else {
                t1 = 1;
                t2 = 2;
                t3 = s - t;
                l = 1;
                r = z;
                while (l < r) {
                    mid = l + (r - l) / 2;
                    if (cnt[t1].query(mid, z) > t3)
                        l = mid + 1;
                    else
                        r = mid;
                }
                X = sm[t1].query(l, z);
                l = z + 1;
                r = n;
                while (l < r) {
                    mid = l + (r - l) / 2 + 1;
                    if (cnt[t2].query(z + 1, mid) > t3)
                        r = mid - 1;
                    else
                        l = mid;
                }
                Y = sm[t2].query(z + 1, l);
                ans += Y - X;
                cerr << X << " " << Y << "!!\n";
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}