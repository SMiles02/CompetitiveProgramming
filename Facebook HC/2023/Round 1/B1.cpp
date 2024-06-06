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

void solve() {
    int n, sum = 0;
    cin >> n;
    vector<int> v;
    for (int i = 2; i <= 41; ++i) {
        while (n % i == 0) {
            sum += i;
            v.push_back(i);
            n /= i;
        }
    }
    if (sum > 41 || n > 1) {
        cout << "-1\n";
    }
    else {
        for (int i = 0; i < 41 - sum; ++i) {
            v.push_back(1);
        }
        cout << v.size() << " ";
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}