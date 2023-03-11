#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int D = 60;
int sz;
ll basis[D];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll L, R, l, r, k;
    cin >> n >> L >> R;
    while (n--) {
        cin >> k;
        for (int i = D - 1; i >= 0; --i)
            if ((1LL << i) & k) {
                if (!basis[i]) {
                    basis[i] = k;
                    ++sz;
                    break;
                }
                k ^= basis[i];
            }
    }
    for (ll i = L; i <= R; ++i) {
        l = 1;
        r = 1LL << sz;
        k = 0;
        for (int j = D - 1; j >= 0; --j)
            if (basis[j]) {
                if ((i <= l + (r - l) / 2) ^ (((1LL << j) & k) == 0))
                    k ^= basis[j];
                if (i <= l + (r - l) / 2)
                    r = l + (r - l) / 2;
                else
                    l += (r - l) / 2 + 1;
            }
        cout << k << " ";
    }
    return 0;
}