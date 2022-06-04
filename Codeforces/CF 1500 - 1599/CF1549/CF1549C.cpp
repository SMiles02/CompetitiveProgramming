#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int sCount, ct[N];
bitset<N> strong;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q,t,x,y;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        strong[i]=1;
    sCount=n;
    while (m--)
    {
        cin>>x>>y;
        if (++ct[min(x,y)]==1)
            --sCount;
    }
    cin>>q;
    while (q--)
    {
        cin>>t;
        if (t==3)
        {
            cout<<sCount<<"\n";
            continue;
        }
        cin>>x>>y;
        if (x<y)
            swap(x,y);
        if (t==1)
        {
            if (++ct[y]==1)
                --sCount;
        }
        else if (--ct[y]==0)
            ++sCount;
    }
    return 0;
}