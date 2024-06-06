#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int K = 3;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ans = 0;
    for (int a = 1; a <= K; ++a) {
        for (int b = 1; b <= K; ++b) {
            for (int c = 1; c <= K; ++c) {
                for (int d = 1; d <= K; ++d) {
                    for (int e = 1; e <= K; ++e) {
                        for (int f = 1; f <= K; ++f) {
                            if (a * b * c != 6 && b * c * d != 6 && c * d * e != 6 && d * e * f != 6) {
                                ++ans;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}