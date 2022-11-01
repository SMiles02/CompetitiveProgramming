#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, sm = 0;
    cin >> n >> k;
    vector<int> dpOld(n + 1), dpNew(n + 1), ans(n + 1), p(n + 1);
    dpOld[0] = 1;
    for (int i = k; sm + k <= n; ++i) {
        sm += i;
        for (int j = 0; j <= n; ++j) {
            if (j < i)
                p[j] = 0;
            else
                p[j] = add(p[j - i], dpOld[j - i]);
            dpNew[j] = p[j];
            ans[j] = add(ans[j], dpNew[j]);
        }
        for (int j = 0; j <= n; ++j)
            dpOld[j] = 0;
        swap(dpNew, dpOld);
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    return 0;
}