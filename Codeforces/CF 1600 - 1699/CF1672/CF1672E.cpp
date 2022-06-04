#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
bool local = 0, printResponse = 0;
int n, l[N], ans[N * N + N], mn[N], mx[N], q, MX, best;
set<array<int, 2>> s;

void updateMin(int qMade, int qAns) {
    if (mn[qAns] != 0 && mn[qAns] <= qMade)
        return;
    if (mn[qAns] != 0)
        s.erase({mn[qAns], qAns});
    s.insert({qMade, qAns});
    best = min(best, qMade * qAns);
    mn[qAns] = qMade;
}

void updateMax(int qMade, int qAns) {
    if (mx[qAns] != 0 && mx[qAns] >= qMade)
        return;
    mx[qAns] = qMade;
}

void update(int qMade, int qAns) {
    if (qAns == 0)
        return;
    updateMin(qMade, qAns);
    updateMax(qMade, qAns);
}

void query(int x) {
    if (ans[x] != -1)
        return;
    --q;
    cout << "? " << x << endl;
    int ret = 0;
    if (local) {
        if (x < MX)
            ret = 0;
        else {
            int cur, pt = 0;
            while (pt < n) {
                ++ret;
                cur = 0;
                while (pt < n && cur + l[pt] <= x) {
                    cur += l[pt] + 1;
                    ++pt;
                }
            }
        }
    }
    else
        cin >> ret;
    ans[x] = ret;
    if (printResponse)
        cout << ret << endl;
    update(x, ret);
}

int main() {
    cin >> n;
    q = n + 30;
    if (local) {
        for (int i = 0; i < n; ++i) {
            cin >> l[i];
            MX = max(MX, l[i]);
        }
    }
    // maximum query you should make is n * 2000 + n - 1
    // which returns 1
    int l = 1, r = 2000, m, x, last;
    best = n * 2000 + n - 1;
    for (int i = 0; i < n * 2001; ++i)
        ans[i] = -1;
    ans[n * 2000 + n - 1] = 1;
    update(n * 2000 + n - 1, 1);
    while (l < r) {
        m = l + (r - l) / 2;
        query(m);
        if (ans[m] == 0)
            l = m + 1;
        else
            r = m;
    }
    last = l;
    x = ans[last] - 1;
    while (x >= 1 && q > 0) {
        l = max(mx[x + 1] + 1, best / x - x);
        array<int, 2> tmp = *(s.upper_bound({last, ans[last]}));
        r = tmp[0];
        // cout << "Searching for " << x << endl;
        // cout << "Searching from " << l << " to " << r << "\n";
        while (l < r && q > 0 && l * x < best) {
            m = l + (r - l) / 2;
            query(m);
            if (ans[m] > x)
                l = m + 1;
            else
                r = m;
        }
        if (q > 0)
            query(l);
        // cerr << l << ": " << ans[l] << "\n";
        last = l;
        x = ans[last] - 1;
    }
    cout << "! " << best << endl;
    if (local)
        cout << "Queries made: " << n + 30 - q << endl;
    return 0;
}