#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

const ll INF = -1e18;
string haha = "haha", ahah = "ahah";

array<array<int,4>,4> calc(string s)
{
    array<array<int,4>,4> a;
    int x=sz(s),ct=0;
    for (int i=0;i+3<x;++i)
        if (s[i]=='h'&&s[i+1]=='a'&&s[i+2]=='h'&&s[i+3]=='a')
            ++ct;
    for (int i=0;i<4;++i)
        for (int j=0;j<4;++j)
        {
            a[i][j]=INF;
            if (max(i,j)>x)
                continue;
            if (i==1&&!(s[0]=='a'))
                continue;
            if (i==2&&!(s[0]=='h'&&s[1]=='a'))
                continue;
            if (i==3&&!(s[0]=='a'&&s[1]=='h'&&s[2]=='a'))
                continue;
            if (j==1&&!(s[x-1]=='h'))
                continue;
            if (j==2&&!(s[x-2]=='h'&&s[x-1]=='a'))
                continue;
            if (j==3&&!(s[x-3]=='h'&&s[x-2]=='a'&&s[x-1]=='h'))
                continue;
            a[i][j]=ct;
        }
    // for (int i=0;i<4;++i)
    //     for (int j=0;j<4;++j)
    //         cout<<i<<" "<<j<<": "<<a[i][j]<<"\n";
    // cout<<"---\n";
    return a;
}

array<array<int,4>,4> merge(array<array<int,4>,4> a, array<array<int,4>,4> b)
{
    array<array<int,4>,4> c;
    for (int i=0;i<4;++i)
        for (int j=0;j<4;++j)
            c[i][j]=INF;
    for (int i=0;i<4;++i)
        for (int j=0;j<4;++j)
            for (int k=0;k<4;++k)
                for (int l=0;l<4;++l)
                {
                    if (j+k==0)
                        c[i][l]=max(c[i][l],a[i][j]+b[k][l]);
                    if (j+k==4)
                        c[i][l]=max(c[i][l],a[i][j]+b[k][l]+1);
                }
    return c;
}

void solve()
{
    int n;
    cin>>n;
    string last,a,b,c,d,e;
    map<string,array<array<int,4>,4>> m;
    while (n--)
    {
        cin>>a>>b>>c;
        if (b[0]==':')
            m[a]=calc(c);
        else
        {
            cin>>d>>e;
            m[a]=merge(m[c],m[e]);
            for (int i=0;i<4;++i)
                for (int j=0;j<4;++j)
                    cout<<i<<" "<<j<<": "<<m[a][i][j]<<"\n";
            // return;
        }
        last=a;
    }
    cout<<m[last][0][0]<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}