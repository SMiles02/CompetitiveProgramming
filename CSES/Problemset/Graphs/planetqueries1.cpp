#include <bits/stdc++.h>
using namespace std;

int lift[30][200001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,y;
    cin>>n>>q;
    for (int i=1;i<=n;++i)
        cin>>lift[0][i];
    for (int j=1;j<30;++j)
        for (int i=1;i<=n;++i)
            lift[j][i]=lift[j-1][lift[j-1][i]];
    while (q--)
    {
        cin>>x>>y;
        for (int i=29;i>=0;--i)
            if ((1<<i)&y)
                x=lift[i][x];
        cout<<x<<"\n";
    }
    return 0;
}