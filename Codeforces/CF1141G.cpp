#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1;
int ct[N], col[N], ans;
vector<array<int,2>> e[N];

void dfs(int c, int p, int x)
{
    int tmp=0;
    for (auto i : e[c])
        if (i[0]!=p)
        {
            if (!col[i[1]])
            {
                if (++tmp==x)
                    ++tmp;
                tmp=min(tmp,ans);
                col[i[1]]=tmp;
                dfs(i[0],c,tmp);
            }
            else
                dfs(i[0],c,col[i[1]]);
        }
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x,y;
    cin>>n>>k;
    vector<int> v(n);
    for (int i=0;i+1<n;++i)
    {
        cin>>x>>y;
        ++ct[x];
        ++ct[y];
        e[x].push_back({y,i});
        e[y].push_back({x,i});
    }
    for (int i=0;i<n;++i)
        v[i]=ct[i+1];
    sort(v.begin(), v.end());
    ans=v[n-k-1];
    cout<<ans<<"\n";
    dfs(1,0,0);
    for (int i=0;i+1<n;++i)
        cout<<col[i]<<" ";
    return 0;
}