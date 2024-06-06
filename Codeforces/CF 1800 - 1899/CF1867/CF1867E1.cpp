#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2505;
int n, k, a[N];
bool local = false;

int query(int i) {
    cout << "? " << i << endl;
    int ret = 0;
    if (local) {
        for (int j = i; j < i + k; ++j) {
            ret ^= a[j];
        }
        for (int j = i; j < i * 2 + k - 1 - j; ++j) {
            swap(a[j], a[i * 2 + k - 1 - j]);
        }
    }
    else {
        cin >> ret;
    }
    return ret;
}

void solve() {
    int cur_xor = 0;
    cin >> n >> k;
    if (local) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
    }
    if (n % k == 0) {
        for (int i = 1; i <= n; i += k) {
            int tmp = query(i);
            cur_xor ^= tmp;
        }
    }
    else {
        for (int i = 1; i + k - 1 <= n; i += k) {
            int tmp = query(i);
            cur_xor ^= tmp;
            if (i + k * 2 - 1 > n) {
                for (int j = i + 1; j + k - 1 <= n; ++j) {
                    tmp = query(j);
                    cur_xor ^= tmp;
                }
            }
        }
    }
    cout << "! " << cur_xor << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}