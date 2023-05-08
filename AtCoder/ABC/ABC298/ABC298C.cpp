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

const int N = 2e5 + 1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<set<int>> w(N);
    vector<map<int, int>> v(n + 1);
    while (q--) {
        int t, i, j;
        cin >> t >> i;
        if (t == 1) {
            cin >> j;
            ++v[j][i];
            w[i].insert(j);
        }
        else if (t == 2) {
            for (auto x : v[i])
                for (auto y = 0; y < x.second; ++y)
                    cout << x.first << " ";
            cout << "\n";
        }
        else {
            for (auto x : w[i])
                cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}