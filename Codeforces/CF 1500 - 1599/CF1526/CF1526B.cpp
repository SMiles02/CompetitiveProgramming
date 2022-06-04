#include <bits/stdc++.h>
using namespace std;

bitset<1101> ok;

void solve()
{
    int n;
    cin>>n;
    if (n<1101&&!ok[n])
        cout<<"NO\n";
    else
        cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ok[0]=1;
    for (int i=11;i<1101;i=i*10+1)
        for (int j=i;j<1101;++j)
            if (ok[j-i])
                ok[j]=1;
    cin>>n;
    while (n--)
        solve();
    return 0;
}