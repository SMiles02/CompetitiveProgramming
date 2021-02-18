#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int x[n],y[n],a,b,c,d;
    for (int i=0;i<n;++i)
        cin>>x[i]>>y[i];
    sort(x,x+n);
    sort(y,y+n);
    a=x[(n-1)/2];
    b=x[n/2];
    c=y[(n-1)/2];
    d=y[n/2];
    cout<<1LL*(b-a+1)*(d-c+1)<<"\n";
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