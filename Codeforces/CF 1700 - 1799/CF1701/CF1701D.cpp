#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}

string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

const int N = 5e5 + 2;
int a[N], b[N];
vector<array<int, 2>> c[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        c[i].clear();
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        if (b[i] == 0)
            c[i + 1].push_back({n, i});
        else
            c[max(1, i / (b[i] + 1) + 1)].push_back({min(n, i / b[i]), i});
    }
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    for (int i = 1; i <= n; ++i) {
        for (auto j : c[i]) {
            pq.push(j);
            // cout << j[1] << ": " << i << " " << j[0] << "\n";
        }
        a[pq.top()[1]] = i;
        pq.pop();
    }
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}