#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 251;
int n;
bitset<N> b;

int query(int x) {
    cout << "? " << x << " ";
    for (int i = 1; i <= n; ++i)
        cout << b[i];
    cout << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, ans;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        b[i] = 1;
    vector<int> cnt(n + 1);
    vector<bool> ok(n + 1, true);
    for (int i = 1; i <= n; ++i) {
        b[i] = 0;
        cnt[i] = query(i);
        b[i] = 1;
    }
    for (int _ = 0; _  < n; ++n)
        for (int i = 1; i <= n; ++i)
            if (cnt[i] == n - 1) {
                cout << "! " << 1 << endl;
                return 0;
            }
    ans = n;
    for (int i = 1; i <= n; ++i)
        if (ok[i] && cnt[i] == 0) {
            for (int j = 1; j <= n; ++j)
                if (ok[j])
                    --cnt[j];
            ok[i] = 0;
            --ans;
        }
    cout << "! " << ans << endl;
    return 0;
}