#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
  
int mn, mx;

void calc(int x) {
    mn = min(mn, x);
    mx = max(mx, x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = -4; i <= 4; ++i)
        for (int j = -4; j <= 4; ++j)
            for (int k = -4; k <= 4; ++k) {
                mn = 0;
                mx = 0;
                if (i+2+j+3+k != 0)
                    continue;
                calc(i);
                calc(i+2);
                calc(i+2+j);
                calc(i+2+j+3);
                cout << i << " " << j << " " << k << ": " << mx-mn+1 << "\n";
            }
    return 0;
}