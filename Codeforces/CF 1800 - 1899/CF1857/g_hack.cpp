// i was dumb, didn't notice people had #define int long long

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    const int T = 1, N = 2e5, S = 1e9, W = 69;
    cout << T << endl;
    cout << N << " " << S << endl;
    for (int i = 1; i < 1e5; ++i) {
        cout << i << " " << i + 1 << " " << W << endl;
    }
    for (int i = 1e5 + 1; i < N; ++i) {
        cout << i << " " << i + 1 << " " << W << endl;
    }
    cout << "1 " << N << " " << W << endl;
    return 0;
}