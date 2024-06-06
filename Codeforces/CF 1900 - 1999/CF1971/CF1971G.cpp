#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

const int I_HATE_DIV4 = (1 << 30) - 4;

void solve() {
    int n;
    cin >> n;
    map<int, priority_queue<int, vector<int>, greater<int>>> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m[a[i] & I_HATE_DIV4].push(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cout << m[a[i] & I_HATE_DIV4].top() << " ";
        m[a[i] & I_HATE_DIV4].pop();
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}