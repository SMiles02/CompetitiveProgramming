#include <bits/stdc++.h>
using namespace std;

bool is_triangular_number(long long n) {
    long long k = sqrt(n * 8 + 1) / 2;
    return (k * (k + 1)) / 2 == n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (is_triangular_number(n)) {
            cout << "1\n";
            continue;
        }
        int ans = 3, cur = 1;
        long long sum = 1;
        while (sum <= n) {
            if (is_triangular_number(n - sum)) {
                ans = 2;
                break;
            }
            sum += ++cur;
        }
        cout << ans << "\n";
    }
    return 0;
}