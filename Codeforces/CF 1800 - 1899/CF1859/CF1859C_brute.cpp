#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 7;
int a[N + 1], ans = 0;
bitset<N + 1> done;

void rec(int i, int sum, int maxi) {
    if (i == N + 1) {
        cout << sum - maxi << ":\n";
        ans = max(ans, sum - maxi);
        for (int j = 1; j <= N; ++j) {
            cout << a[j] << " ";
        }
        cout << "\n";
        return;
    }
    for (int j = 1; j <= N; ++j) {
        if (!done[j]) {
            a[i] = j;
            done[j] = 1;
            rec(i + 1, sum + i * j, max(maxi, i * j));
            done[j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    rec(1, 0, 0);
    cerr << ans;
    return 0;
}