#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, d;
    cin >> a >> b >> d;
    for (int i = d; i <= 100000; i += d)
        if ((i & (a | b)) == (a | b))
            cout << i << " " << (a | b | i) << "\n";
    return 0;
}