#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, cnt = 0;
    cin >> n >> k;
    vector<int> x(n);
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        cnt += ++m[x[i]] == 1;
        if (i + 1 >= k) {
            cout << cnt << " ";
            cnt -= --m[x[i - k + 1]] == 0;
        }
    }
    return 0;
}