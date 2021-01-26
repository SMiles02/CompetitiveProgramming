#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int h,w;

bool ok(int x, int y)
{
    if (0<x&&0<y&&x+2<=h&&y+2<=w)
        return 1;
    return 0;
}

ll ans[10];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    cin>>h>>w>>n;
    set<array<int,2>> b,s;
    while (n--)
    {
        cin>>x>>y;
        b.insert({x,y});
        for (int i=-2;i<1;++i)
            for (int j=-2;j<1;++j)
                if (ok(x+i,y+j))
                    s.insert({x+i,y+j});
    }
    for (array<int,2> i : s)
    {
        int c=0;
        for (int j=0;j<3;++j)
            for (int k=0;k<3;++k)
                if (b.find({i[0]+j,i[1]+k})!=b.end())
                    ++c;
        //if (c)
        //    cout<<i[0]<<" "<<i[1]<<": "<<c<<"\n";
        ++ans[c];
    }
    ans[0]=1LL*(h-2)*(w-2);
    //cout<<ans[0]<<"!\n";
    for (int i=1;i<10;++i)
        ans[0]-=ans[i];
    for (int i=0;i<10;++i)
        cout<<ans[i]<<"\n";
    return 0;
}