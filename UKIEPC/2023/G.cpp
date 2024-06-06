#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll s(int x) {
    return 1LL * x * x;
}

double d(int a, int b, int c, int d) {
    return sqrt(s(a - c) + s(b - d));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int s, n;
    cin >> s;
    cin >> n;
    vector<array<int, 2>> a(n + 1);
    vector<double> p(n + 1);
    double ans = s;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i][0] >> a[i][1];
        if (i > 1) {
            p[i] = p[i - 1] + d(a[i - 1][0], a[i - 1][1], a[i][0], a[i][1]);
        }
    }
    cout << fixed << setprecision()
    return 0;
}