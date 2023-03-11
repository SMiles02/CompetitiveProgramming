#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MN = -6, MX = 6, N = 3;
int a[N];

void rec(int i) {
    if (i == N) {
        int s = 0;
        for (int j = 0; j < N; ++j)
            s += a[j];
        for (int j = 1; j < N; ++j)
            if (a[j - 1] + a[j] != s)
                return;
        for (int j = 0; j < N; ++j)
            cout << a[j] << " ";
        cout << endl;
        return;
    }
    for (int j = MN; j <= MX; ++j)
        if (j != 0) {
            a[i] = j;
            rec(i + 1);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    rec(0);
    return 0;
}