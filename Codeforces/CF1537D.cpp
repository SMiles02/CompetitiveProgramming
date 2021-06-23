#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    if (__builtin_popcount(n)==1)
        for (long long i=2;i<1e9;i*=4)
            if (n==i)
            {
                cout<<"Bob\n";
                return;
            }
    if ((n&1))
        cout<<"Bob\n";
    else
        cout<<"Alice\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}