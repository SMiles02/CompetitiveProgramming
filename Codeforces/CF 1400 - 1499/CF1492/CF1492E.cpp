#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

int n,m;
vector<vector<int>> v;

bool solve(int k)
{
    for (int i=1;i<n;++i)
    {
        vector<int> w,x;
        for (int j=0;j<m;++j)
            if (v[0][j]!=v[i][j])
            {
                w.push_back(j);
                if (sz(w)-k>2)
                    return 0;
            }
        if (sz(w)<3)
            continue;
        for (int j : w)
            x.push_back(v[0][j]);
        for (int j=1;j<(1<<sz(w));++j)
        {
            if (sz(w)-__builtin_popcount(j)<3&&__builtin_popcount(j)<=k)
            {
                for (int l=0;l<sz(w);++l)
                    if (j&(1<<l))
                        v[0][w[l]]=v[i][w[l]];
                if (solve(k-__builtin_popcount(j)))
                    return 1;
                for (int l=0;l<sz(w);++l)
                    if (j&(1<<l))
                        v[0][w[l]]=x[l];
            }
        }
        return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    v.resize(n,vector<int>(m));
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>v[i][j];
    if (solve(2))
    {
        cout<<"Yes\n";
        for (int j=0;j<m;++j)
            cout<<v[0][j]<<" ";
    }
    else
        cout<<"No";
    return 0;
}