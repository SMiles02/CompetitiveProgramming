#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2023;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i <= N; ++i)
        for (int j = i + 1; j <= N; ++j)
            for (int k = j + 1; k <= N; ++k)
                if ((1LL * i * j * k) % (1LL * j * k + 1LL * i * j + 1LL * i * k) == 0) {
                    cout << (1LL * i * j * k) / (1LL * j * k + 1LL * i * j + 1LL * i * k) << " " << i << " " << j << " " << k << "\n";
                }
    return 0;
}