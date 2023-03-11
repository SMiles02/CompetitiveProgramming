#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 1, L = 40;
int n, q, x, a[N], nxt[N];
array<int, 2> up[N][L];
ll p[N];



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
        nxt[i] = i + 1;
    }
    nxt[n] = 1;
    for (int i = n + 1; i <= n * 2; ++i)
        p[i] = p[i - 1] + a[i - n];
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = x, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (check(i, m) < x)
                l = m + 1;
            else
                r = m;
        }
    }
    return 0;
}