#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2;
int a[N];
set<int> s;

bool check_odd(int diff, int dv, int i, int j) {
    // centred at dv
    int opp = diff / dv; // this is odd (total number of elements in seq)
    int y = dv - (opp / 2) * 2;
    if (y < 1)
        return false;
    int x = y / 2;
    x *= x;
    x -= a[i];
    if (x < 0)
        return false;
    // cout << a[i] << " " << a[j] << " " << x << "\n";
    s.insert(x);
    return true;
}

bool check_even(int diff, int dv, int i, int j) {
    int opp = diff / dv; // total number of elements
    if ((opp & 1) || opp < 2)
        return false;
    int y = (dv + 1) - (opp / 2) * 2;
    if (y < 1)
        return false;
    int x = y / 2;
    x *= x;
    x -= a[i];
    if (x < 0)
        return false;
    // cout << a[i] << " " << a[j] << " " << x << "\n";
    s.insert(x);
    return true;
}

bool check(int diff, int dv, int i, int j) {
    if (diff & 1)
        return check_odd(diff, dv, i, j);
    return check_even(diff, dv, i, j);
}

ll stupid(ll x) {
    ll l = 1, r = 1e9, m;
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        if (m * m > x)
            r = m - 1;
        else
            l = m;
    }
    return l;
}

bool is_square(ll x) {
    ll tmp = stupid(x);
    return (tmp * tmp == x);
}

const int MX = 500;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // for (int i = 1; i <= MX; ++i)
    //     for (int j = i + 1; j <= MX; ++j) {
    //         s.clear();
    //         a[0] = i;
    //         a[1] = i;

    //     }
    int ans;
    for (int i = 1; i <= MX; ++i)
        for (int j = i + 1; j <= MX; ++j) {
            a[0] = i;
            a[1] = j;
            s.clear();
            for (int k = 1; k * k <= j - i; ++k)
                if ((j - i) % k == 0) {
                    if (check(j - i, k, 0, 1))
                        ans = 2;
                    if (check(j - i, (j - i) / k, 0, 1))
                        ans = 2;
                }
            for (int k = 0; k <= MX * 10; ++k)
                if (i <= k * k && is_square(j + k * k - i) && s.count(k * k - i) == 0) {
                    cout << "fuck\n";
                    cout << i << " " << j << " " << k * k - i << "\n";
                    return 0;
                }
        }
    cout << "kms\n";
    return 0;
}