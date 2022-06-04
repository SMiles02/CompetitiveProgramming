#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,p,w,d,x;
    cin>>n>>p>>w>>d;
    for (int y=0;y<w;++y)
    {
        if (!((p-d*y)%w))
        {
            x=((p-d*y)/w);
            if (x+y<=n&&x>=0)
            {
                cout<<x<<" "<<y<<" "<<n-x-y;
                return 0;
            }
        }
    }
    cout<<-1;
    return 0;
}