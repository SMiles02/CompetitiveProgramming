#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    cin >> n;
    cout << "? " << n << " 1" << endl;
    cin >> x;
    if (x == n) {
        cout << "! " << n << " 1" << endl;
        return 0;
    }
    cout << "? " << n - x << " 1" << endl;
    cin >> y;
    cout << "! " << x << " " << y << endl;
    return 0;
}