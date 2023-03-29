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

int f(int x) {
    return (x * (x + 1)) / 2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<array<int, 2>> v;
    for (int i = 1; i <= 10; ++i)
        for (int j = 0; j <= f(i); ++j)
            v.push_back({i, j});
    cout << v.size() << " \n";
    for (auto i : v)
        cout << i[0] << " " << i[1] << "\n";
    return 0;
}