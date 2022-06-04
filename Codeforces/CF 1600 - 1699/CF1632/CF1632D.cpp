#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

const int N = 2e5 + 1;
int sparse[200001][18];

int query(int l, int r) {
    int ret = 0;
    for (int i = 17; i >= 0; --i)
        if (l + (1 << i) - 1 <= r) {
            ret = gcd(ret, sparse[l][i]);
            l += (1 << i);
        }
    return ret;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, ans = 0, block = 0, l, r, g;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = n; i > 0; --i) {
        sparse[i][0] = a[i];
        for (int j = 1; i + (1 << j) - 1 <= n; ++j)
            sparse[i][j] = gcd(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1) {
            cout << ++ans << " ";
            block = i;
            continue;
        }
        r = i;
        while (r > block) {
            g = query(r, i);
            l = r;
            for (int j = 17; j >= 0; --j)
                if (l - (1 << j) + 1 > block && gcd(g, sparse[l - (1 << j) + 1][j]) == g)
                    l = l - (1 << j) + 1;
            if (i - r + 1 <= g && g <= i - l + 1) {
                ++ans;
                block = i;
                break;
            }
            r = l - 1;
        }
        cout << ans << " ";
    }
    return 0;
}