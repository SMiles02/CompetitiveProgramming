#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n = 3, k = 10, m = 15;
    for (int a = 1; a < k; ++a)
        for (int b = 1; b <= m; ++b)
            if (k <= a + b)
                for (int c = 1; c <= m; ++c)
                    for (int d = 1; d <= m; ++d)
                        for (int e = 1; e <= m; ++e)
                            for (int f = 1; f <= m; ++f)
                                if (c + d > e + f && k <= min(min(c, e) + f, a) + b && min(min(c, e) + d, a) + b < k && !(k - b <= min(a, max(c, e)))) {
                                    cout << "1\n";
                                    cout << n << " " << k << "\n";
                                    cout << a << " " << b << "\n";
                                    cout << c << " " << d << "\n";
                                    cout << e << " " << f << "\n";
                                    return 0;
                                }
    return 0;
}