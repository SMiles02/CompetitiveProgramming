#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,m,B=0,W=0,x,y;
    int a=0,b=0,c=0,d=0;
    cin>>n>>m;
    while (m--)
    {
        cin>>x>>y;
        if ((x+y)&1)
            ++B;
        else
            ++W;
        if (x==1)
        {
            if (y&1)
                ++a;
            else
                ++b;
        }
        else
        {
            if (y&1)
                ++c;
            else
                ++d;
        }

    }
    if (W==B&&a<2&&b<2&&c<2&&d<2)
        cout<<"YES\n";
    else
        cout<<"NO\n";
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