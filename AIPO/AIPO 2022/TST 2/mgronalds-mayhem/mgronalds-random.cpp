#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 5;
int w[N];
vector<int> a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k, x;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        while (k--)
            cin >> x;
    }
    for (int i = 1; i <= m; ++i)
        cin >> w[i];
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    shuffle(v.begin(), v.end(), rng);
    cout << "YES\n";
    for (int i : v)
        cout << i << " ";
    return 0;
}