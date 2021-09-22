#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+1;
int p[N];

void solve()
{
    int a, b, x, ans;
    cin>>a>>b;
    x = p[a-1];
    ans = a;
    if (x != b)
    {
        ++ans;
        if ((x^b) == a)
            ++ans;
    }
    cout << ans << "\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=1;i<N;++i)
        p[i] = p[i-1] ^ i;
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}