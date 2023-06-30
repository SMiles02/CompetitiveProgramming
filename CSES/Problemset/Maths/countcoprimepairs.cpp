#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
int cnt[N];
vector<int> pf[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i < N; ++i)
        if (pf[i].empty())
            for (int j = i; j < N; j += i)
                pf[j].push_back(i);
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ans += i;
        for (int j = 1; j < (1 << pf[x].size()); ++j) {
            int prod = 1;
            for (int k = 0; k < pf[x].size(); ++k)
                if (j & (1 << k))
                    prod *= pf[x][k];
            if (__builtin_popcount(j) & 1)
                ans -= cnt[prod];
            else
                ans += cnt[prod];
            ++cnt[prod];
        }
    }
    cout << ans;
    return 0;
}