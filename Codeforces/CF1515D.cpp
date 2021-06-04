#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,l,r,k,ans=0,x=0,y=0,s=0,t=0;
    cin>>n>>l>>r;
    map<int,int> m1,m2;
    while (l--)
    {
        cin>>k;
        ++m1[k];
    }
    while (r--)
    {
        cin>>k;
        if (m1[k])
            --m1[k];
        else
            ++m2[k];
    }
    for (auto i : m1)
    {
        s+=i.second&1;
        x+=i.second/2;
    }
    for (auto i : m2)
    {
        t+=i.second&1;
        y+=i.second/2;
    }
    while (min(x+s,y+t)>0)
    {
        ++ans;
        if (s)
            --s;
        else
            --x,++s;
        if (t)
            --t;
        else
            --y,++t;
    }
    cout<<ans+x+y+s+t<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}