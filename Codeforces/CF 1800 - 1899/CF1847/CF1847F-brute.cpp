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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<set<int>> v(n * n);
    for (int i = 1; i <= n; ++i) {
        v[i].insert(i);
        cout << i << ", 1: " << i << "\n";
    }
    for (int i = n + 1; v[i - 1].size() < n; ++i) {
        for (int j : v[i - n]) {
            v[i].insert(j);
        }
        for (int j : v[i - n + 1]) {
            v[i].insert(j);
        }
        cout << i << ", " << v[i].size() << ": ";
        for (int j : v[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}