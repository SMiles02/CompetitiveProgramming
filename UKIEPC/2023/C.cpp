#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define double long double
using namespace std;

const int N = 102;
const double INF = -1e18;
const double C = 3.14159265358979323846264338327950288419 / 180;
double x[N], y[N], dp[N][N];

double get_area(int i, int j, int k) {
    double x1 = x[i], x2 = x[j], x3 = x[k];
    double y1 = y[i], y2 = y[j], y3 = y[k];
    return abs(((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1))) / 2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, p;
    double ans = 0;
    cin >> n;
    cin >> p;
    vector<double> a(n); // making input angles doubles is literally the dumbest possible problemsetting i have seen
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        x[i] = cos(C * a[i]) * 1000;
        y[i] = sin(C * a[i]) * 1000;
    }
    for (int s = 0; s < n; ++s) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= p; ++j) {
                dp[i][j] = INF;
            }
        }
        dp[s][1] = 0;
        for (int i = s + 1; i < n; ++i) {
            for (int j = 2; j <= p; ++j) {
                for (int k = s; k < i; ++k) {
                    dp[i][j] = max(dp[i][j], dp[k][j - 1] + get_area(s, k, i));
                }
            }
            ans = max(ans, dp[i][p]);
        }
    }
    cout << fixed << setprecision(8) << ans;
    return 0;
}