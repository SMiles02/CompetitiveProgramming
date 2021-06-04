#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,k,x,y;
bitset<20> d;

void solve()
{
    int c=0;
    for (int i=1;i<=n;++i)
    {
        if (d[i])
            ++c;
        else
            c=0;
        if (c==k)
        {
            x+=d.count();
            ++y;
            return;
        }
    }
    for (int i=1;i<=n;++i)
        if (!d[i])
        {
            d[i]=1;
            solve();
            d[i]=0;
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (n=1;n<=6;++n)
        for (k=1;k<=n;++k)
        {
            x=0;y=0;
            solve();
            cout<<n<<" "<<k<<": "<<x<<"/"<<y<<"\n";
        }
    return 0;
}