#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x, y;
    cin >> x >> y;
    cout << fixed << setprecision(10) << (double)(100*(x-y))/x;
    return 0;
}