#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n=1e5,m=2e5-3;
    cout<<n<<" "<<m<<"\n";
    for (int i=1;i<3;++i)
        for (int j=i+1;j<=n;++j)
            cout<<i<<" "<<j<<" 21\n";
    return 0;
}