//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5+7, L = 17, INF = 1e9;
int ans[N][L];
vector<array<int,2>> v[N];
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q,l,r,mid,tg,x,y,z,c;
    cin>>n>>m>>q;
    array<int,4> bus[m];
    for (int i=0;i<N;++i)
        for (int j=0;j<L;++j)
            ans[i][j]=INF;
    for (int i=0;i<m;++i)
        cin>>bus[i][2]>>bus[i][3]>>bus[i][0]>>bus[i][1];
    sort(bus,bus+m);
    for (int i=m-1;i>=0;--i)
    {
        tg=bus[i][3];
        if (!v[tg].empty()&&v[tg][0][0]>=bus[i][1])
        {
            l=0;
            r=sz(v[tg])-1;
            while (l<r)
            {
                mid=l+(r-l)/2+1;
                if (v[tg][mid][0]<bus[i][1])
                    r=mid-1;
                else
                    l=mid;
            }
            ans[i][0]=v[tg][l][1];
            // cout<<bus[i][2]<<" to "<<bus[i][3]<<", followed by ";
            // cout<<bus[ans[i][0]][2]<<" to "<<bus[ans[i][0]][3]<<"\n";
        }
        v[bus[i][2]].push_back({bus[i][0],i});
        for (int j=1;j<L;++j)
            if (ans[i][j-1]!=INF)
                ans[i][j]=ans[ans[i][j-1]][j-1];
    }
    while (q--)
    {
        cin>>x>>y>>z;
        if (v[y].empty())
        {
            cout<<y<<"\n";
            continue;
        }
        l=0;r=sz(v[y])-1;
        while (l<r)
        {
            mid=l+(r-l)/2+1;
            if (v[y][mid][0]<x)
                r=mid-1;
            else
                l=mid;
        }
        if (v[y][l][0]>=z||v[y][l][0]<x)
        {
            cout<<""<<y<<"\n";
            continue;
        }
        c=v[y][l][1];
        //cout<<"! "<<c<<"\n";
        //cout<<z<<" "<<
        // cout<<"nothing\n";
        // continue;
        for (int i=L-1;i>=0;--i)
        {
            //cerr<<i<<" "<<c<<"\n";
            if (ans[c][i]!=INF&&bus[ans[c][i]][0]<z)
                c=ans[c][i];
        }
        if (bus[c][1]<z)
            cout<<bus[c][3]<<"\n";
        else
        {
            //cout<<"? ";
            cout<<bus[c][2]<<" "<<bus[c][3]<<"\n";
        }
        // else
        //     cout<<"nothing yet\n";
    }
    return 0;
}