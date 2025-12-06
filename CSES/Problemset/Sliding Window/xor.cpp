#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int x[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, a, b, c;
    cin >> n >> k;
    long long sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            cin >> x[i] >> a >> b >> c;
        }
        else {
            x[i] = (1LL * x[i - 1] * a + b) % c;
        }
        sum ^= x[i];
        if (i + 1 >= k) {
            ans ^= sum;
            sum ^= x[i - k + 1];
        }
    }
    cout << ans;
    return 0;
}