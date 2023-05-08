#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;

vector<vector<int>> rotate(vector<vector<int>> a) {
    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[i][j] = a[n - j - 1][i];
    return b;
}

bool equals(vector<vector<int>> &a, vector<vector<int>> &b) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] == 1 && b[i][j] == 0)
                return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> b[i][j];
    for (int i = 0; i < 4; ++i) {
        if (equals(a, b)) {
            cout << "Yes";
            return 0;
        }
        a = rotate(a);
    }
    cout << "No";
    return 0;
}