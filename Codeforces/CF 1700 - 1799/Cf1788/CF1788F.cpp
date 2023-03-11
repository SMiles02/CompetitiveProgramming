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

ll f(int x) {
    return (1LL * x * (x + 1)) / 2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i <= 1000; i += 2)
        if (f(i * 2) % i == 0) {
            int x, y;
            ll cur = f(i * 2);
            bool ans = false;
            for (int j = i; j <= i * 4 - 1; ++j) {
                if (cur == (f(j) - f(j - i)) && 3 <= j - i + 1) {
                    ans = true;
                    x = j - i + 1;
                    y = j;
                }
            }
            if (ans)
                cout << i << " " << x << " " << y << "\n";
        }
    cout << "done\n";
    return 0;
}