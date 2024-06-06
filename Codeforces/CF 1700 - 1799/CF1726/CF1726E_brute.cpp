#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 20;
bitset<N> done;
int n, a[N], pos[N];

void rec(int i) {
    if (i > n) {
        for (int j = 1; j <= n; ++j) {
            if (abs(a[j] - pos[j]) > 1) {
                return;
            }
        }
        for (int j = 1; j <= n; ++j) {
            cout << a[j] << " ";
        }
        cout << "\n";
        return;
    }
    for (int j = 1; j <= n; ++j) {
        if (!done[j]) {
            a[i] = j;
            pos[j] = i;
            done[j] = 1;
            rec(i + 1);
            done[j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rec(1);
    return 0;
}