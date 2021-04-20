#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k,x,y,d=0;
    cin>>n>>k;
    if (k>(n-1)/2)
    {
        cout<<"-1\n";
        return;
    }
    x=1;y=n;
    for (int i=0;i<n;++i)
    {
        if ((i&1)&&d<k)
        {
            cout<<y--<<" ";
            ++d;
        }
        else
            cout<<x++<<" ";
    }
    cout<<"\n";
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