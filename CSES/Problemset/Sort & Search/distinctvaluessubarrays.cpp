#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, last_dupe = 0;
    long long ans = 0;
    cin >> n;
    map<int, int> last_occ;
    for (int i = 1, k; i <= n; ++i) {
        cin >> k;
        last_dupe = max(last_dupe, last_occ[k]);
        last_occ[k] = i;
        ans += i - last_dupe;
    }
    cout << ans;
    return 0;
}