#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, ans = 1;
    cin >> n;
    map<int, int> cnt;
    while (n--) {
        cin >> k;
        ++cnt[k];
    }
    for (auto i : cnt) {
        ans = (1LL * ans * (i.second + 1)) % MOD;
    }
    cout << (ans + MOD - 1) % MOD;
    return 0;
}