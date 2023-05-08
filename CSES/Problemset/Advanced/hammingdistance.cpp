#include <bits/stdc++.h>
using namespace std;

const int N = 2e4, K = 30;
bitset<K> a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, ans = 30;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < k; ++j)
            if (s[j] == '1')
                a[i][j] = 1;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            ans = min(ans, (int)(a[i] ^ a[j]).count());
    cout << ans;
    return 0;
}