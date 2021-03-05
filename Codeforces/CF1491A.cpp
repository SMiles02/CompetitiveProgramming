#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,o=0,x,y;
    cin>>n>>q;
    int a[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        o+=a[i];
    }
    while (q--)
    {
        cin>>x>>y;
        if (x==1)
        {
            if (a[y])
                --o;
            else
                ++o;
            a[y]^=1;
        }
        else
        {
            if (o>=y)
                cout<<"1\n";
            else
                cout<<"0\n";
        }
    }
    return 0;
}