#include <bits/stdc++.h>
using namespace std;

int x;

int calc_score(vector<int> v) {
    vector<int> w(10);
    bool ok;
    for (int i = 0; i < (1 << 9); ++i) {
        ok = true;
        for (int j = 0; j < 9; ++j)
            if ((i & (1 << j)) && v[j] < 3)
                ok = false;
        if (!ok)
            continue;
        for (int j = 0; j < 9; ++j) {
            for (int k = 0; k < 9; ++k) {
                if (i & (1 << k))
                    w[k] = v[k] - 3;
                else
                    w[k] = v[k];
            }
            if (w[j] < 2)
                continue;
            w[j] -= 2;
            for (int k = 0; k < 7; ++k)
                while (w[k] && w[k + 1] && w[k + 2]) {
                    --w[k];
                    --w[k + 1];
                    --w[k + 2];
                }
            ok = true;
            for (int k = 0; k < 9; ++k)
                if (w[k])
                    ok = false;
            if (ok)
                return v[x] + 1;
        }
    }
    return 0;
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> x;
    --x;
    vector<int> v(9);
    int k;
    double ans = 0, cur = 0;
    for (int i = 0; i < 14; ++i) {
        cin >> k;
        ++v[--k];
    }
    for (int i = 0; i < 9; ++i)
        if (v[i]) {
            --v[i];
            cur = 0;
            for (int j = 0; j < 9; ++j) {
                ++v[j];
                cur += ((double)(4 - v[j] + 1 - (i == j)) / 22) * calc_score(v);
                --v[j];
            }
            ans = max(ans, cur);
            ++v[i];
        }
    cout << fixed << setprecision(9) << ans;
    return 0;
}