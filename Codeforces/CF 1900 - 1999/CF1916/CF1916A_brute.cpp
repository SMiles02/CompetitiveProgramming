#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i <= 2023; ++i) {
        for (int j = i; j <= 2023; ++j) {
            for (int k = j; k <= 2023; ++k) {
                for (int l = k; l <= 2023; ++l) {
                    for (int m = l; m <= 2023; ++m) {
                        if (1LL * i * j * k * l * m > 2023 && 2023 % ((((i * j) * k) * l) * m) == 0) {
                            cout << i << " " << j << " " << k << " " << l << "\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}