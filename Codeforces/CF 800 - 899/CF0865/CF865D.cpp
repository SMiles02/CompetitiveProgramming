#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n;
    long long ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1e6);
    while (n--) {
        cin >> k;
        if (pq.top() < k) {
            ans += k - pq.top();
            pq.pop();
            pq.push(k);
        }
        pq.push(k);
    }
    cout << ans;
    return 0;
}