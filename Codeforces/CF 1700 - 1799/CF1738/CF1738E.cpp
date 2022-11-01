#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 5;
int a[N], b[N + 1], x, y;
bitset<N + 1> dn;

void print(int k) {
    x = N + 1;
    y = 0;
    for (int i = 0; i < N; ++i) {
        if (a[i] <= k) {
            b[a[i]] = x;
            y = a[i];
        }
        else {
            b[a[i]] = y;
            x = a[i];
        }
    }
    cout << N << "\n";
    for (int i = 1; i <= N; ++i)
        cout << b[i] << " ";
    cout << "\n";
}

void rec(int x) {
    if (x == N) {
        for (int i = 1; i <= N; ++i)
            print(i);
        return;
    }
    for (int i = 1; i <= N; ++i)
        if (!dn[i]) {
            a[x] = i;
            dn[i] = 1;
            rec(x + 1);
            dn[i] = 0;
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    rec(0);
    return 0;
}