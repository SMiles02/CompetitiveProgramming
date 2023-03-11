#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int digit_sum(int x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    if (abs(digit_sum(n / 2) - digit_sum((n + 1) / 2)) <= 1)
        cout << n / 2 << " " << (n + 1) / 2 << "\n";
    else {
        int x = 0, y = 0, cnt = 0;
        for (ll i = 1; i <= 1e9; i *= 10) {
            if (n % 2) {
                if (cnt & 1) {
                    x += ((n % 10) / 2) * i;
                    y += (((n % 10) + 1) / 2) * i;
                }
                else {
                    y += ((n % 10) / 2) * i;
                    x += (((n % 10) + 1) / 2) * i;
                }
                ++cnt;
            }
            else {
                x += ((n % 10) / 2) * i;
                y += ((n % 10) / 2) * i;
            }
            n /= 10;
        }
        cout << x << " " << y << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}