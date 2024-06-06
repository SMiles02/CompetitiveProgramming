#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (long long i = 1; i <= 20; ++i) {
        cout << (MOD - i) % MOD << "\n";
    }
    return 0;
}