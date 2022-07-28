#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N], b[N], p[N], seen[N], cnt_b[N], end_at[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k = 0, x = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        ++cnt_b[b[i]];
        x = max(x, a[i]);
        end_at[a[i]] = max(end_at[a[i]], b[i]);
    }
    for (int i = 1; i <= m; ++i) {
        ++p[max(k, x) - i + 1];
        --p[m - i + 2];
        k = max(k, end_at[i]);
        if (cnt_b[i])
            break;
    }
    for (int i = 1; i <= m; ++i) {
        p[i] += p[i - 1];
        cout << p[i] << " ";
    }
    return 0;
}