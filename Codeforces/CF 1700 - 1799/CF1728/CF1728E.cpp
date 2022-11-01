#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll normal_gcd(ll a, ll b) {
    if (b == 0) return a;
    return normal_gcd(b, a % b);
}

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

const int N = 3e5 + 5;
int n, a[N], b[N], c[N];
ll pre[N], suf[N], sc[N], d[101][N];

void build(int x) {
    cerr << x << endl;
    for (int i = 0; i < x; ++i) {
        for (int j = i; j <= n; j += x)
            d[x][i] = max(d[x][i], sc[j]);
        // cerr << d[x][i] << " ";
    }
    // cerr << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m, cur = 0, x, y, t;
    ll l, ans;
    cin >> n;
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        s += min(a[i], b[i]);
        c[i] = b[i] - a[i];
    }
    sort(c, c + n);
    pre[0] = s;
    for (int i = 0; i < n; ++i)
        pre[i + 1] = pre[i] + max(0, -c[i]);
    suf[n + 1] = 0;
    for (int i = n - 1; i >= 0; --i)
        suf[i + 1] = suf[i + 2] + max(0, c[i]);
    for (int i = 0; i <= n; ++i) {
        sc[i] = pre[i] + suf[i + 1];
        cerr << sc[i] << " ";
    }
    cerr << endl;
    map<int, int> mp;
    for (int i = 1; i <= min(n, 100); ++i)
        build(i);
    cin >> m;
    while (m--) {
        cin >> x >> y;
        t = find_all_solutions(x, y, n, 0, n / x, 0, n / y);
        if (t == 0)
            cout << "-1\n";
        else {
            l = (1LL * x * y) / normal_gcd(x, y);
            if (l <= n) {
                if (l <= 100)
                    cout << d[l][(t * x) % l] << "\n";
                else {
                    ans = 0;
                    for (int i = t * x; i <= n; i += l) {
                        ans = max(ans, sc[i]);
                    }
                    for (int i = t * x; i >= 0; i -= l) {
                        ans = max(ans, sc[i]);
                    }
                    cout << ans << "\n";
                }
            }
            else {
                cout << t << " " << x << ": ";
                cout << sc[t * x] << " !!\n";
            }
        }
    }
    return 0;
}