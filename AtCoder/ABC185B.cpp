#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,t,x,y,c;
    cin>>n>>m>>t;
    y=0;
    c=n;
    while (m--)
    {
        cin>>x;
        c-=(x-y);
        if (c<=0)
        {
            cout<<"No";
            return 0;
        }
        cin>>y;
        c=min(c+y-x,n);
    }
    c-=(t-y);
    if (c<=0)
        cout<<"No";
    else
        cout<<"Yes";
    return 0;
}