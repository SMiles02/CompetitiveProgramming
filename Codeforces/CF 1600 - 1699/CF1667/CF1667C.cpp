#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, b;
    cin >> n;
    if (n == 1) {
        cout << "1\n1 1";
        return 0;
    }
    if (n % 3 == 2) {
        b = (n / 3) * 2 + 1;
        k = (n / 3) * 2 + 1;
    }
    else if (n % 3 == 1) {
        b = ((n - 2) / 3) * 2 + 1;
        k = ((n - 2) / 3) * 2 + 3;
    }
    else {
        b = ((n - 1) / 3) * 2 + 1;
        k = ((n - 1) / 3) * 2 + 2;
    }
    cout << k << "\n";
    cout << "1 1\n";
    int diff = 1;
    vector<bool> dn(n + 1);
    dn[1] = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 2; i <= n; ++i)
        pq.push(i);
    for (int i = 1; i < b; i += 2) {
        while (dn[pq.top()])
            pq.pop();
        cout << pq.top() << " " << pq.top() + diff << "\n";
        cout << pq.top() + diff << " " << pq.top() << "\n";
        dn[pq.top()] = true;
        dn[pq.top() + diff] = true;
        ++diff;
    }
    if (n % 3 == 1) {
        cout << n - 1 << " " << n - 1 << "\n";
        cout << n << " " << n << "\n";
    }
    else if (n % 3 == 0) {
        cout << n << " " << n << "\n";
    }
    return 0;
}