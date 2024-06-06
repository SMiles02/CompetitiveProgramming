#include <bits/stdc++.h>
using namespace std;

int make_query(int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    char ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n, mx = 0, cd = 0;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        char qv = make_query(mx, mx, i, i);
        if (qv == '<') {
            mx = i;
        }
    }
    for (int i = 1; i < n; ++i) {
        char qv = make_query(mx, cd, mx, i);
        if (qv == '<') {
            cd = i;
        }
        else if (qv == '=') {
            qv = make_query(cd, cd, i, i);
            if (qv == '>') {
                cd = i;
            }
        }
    }
    cout << "! " << mx << " " << cd << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}