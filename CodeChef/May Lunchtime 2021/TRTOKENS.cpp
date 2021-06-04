#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e6+5, L = 21;
int up[L][N], s[N], h[N];
bitset<N> token, placed;
vector<int> e[N];

void dfs(int c)
{
    if (placed[up[0][c]]&&token[c])
        placed[c]=1;
    s[c]=0;
    for (int i=1;i<L;++i)
        up[i][c]=up[i-1][up[i-1][c]];
    for (int i : e[c])
    {
        up[0][i]=c;
        h[i]=h[c]+1;
        dfs(i);
        s[c]=max(s[c],s[i]);
    }
    s[c]+=token[c];
}

void solve()
{
    int n,k;
    ll ans=0;
    cin>>n;
    char c;
    vector<array<int,3>> v;
    vector<int> w;
    placed[0]=1;
    for (int i=1;i<=n;++i)
    {
        e[i].clear();
        cin>>c;
        token[i]=(c-'0');
    }
    for (int i=2;i<=n;++i)
    {
        cin>>k;
        e[k].push_back(i);
    }
    dfs(1);
    for (int i=1;i<=n;++i)
        if (token[i])
            v.push_back({h[i],s[i],i});
    sort(v.rbegin(), v.rend());
    for (auto i : v)
    {
        //cout<<i[0]<<" "<<i[1]<<"\n";
        k=i[2];
        if (placed[k])
            continue;
        for (int j=L-1;j>=0;--j)
            if (!placed[up[j][k]])
            {
                ans+=1<<j;
                k=up[j][k];
            }
        w.push_back(k);
        //cout<<i[2]<<" to "<<k<<"\n";
        placed[k]=1;
        while (!w.empty())
        {
            k=w.back();
            w.pop_back();
            for (int i : e[k])
                if (token[i])
                {
                    placed[i]=1;
                    w.push_back(i);
                }
        }
    }
    cout<<ans<<"\n";
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