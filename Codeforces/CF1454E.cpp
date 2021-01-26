#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 2e5+1;
vector<int> edges[mn];
bitset<mn> done,cycle;
int p[mn],h[mn],l;
 
void buildAns(int x, int y)
{
    deque<int> d;
    d.push_back(x);
    d.push_back(y);
    while (d.front()!=d.back())
    {
        if (h[d.front()]>h[d.back()])
            d.push_front(p[d.front()]);
        else
            d.push_back(p[d.back()]);
    }
    for (int i : d)
        cycle[i]=1;
}

void dfs(int c)
{
    done[c]=1;
    ++l;
    for (int i : edges[c])
        if (!done[i]&&!(cycle[c]&&cycle[i]))
            dfs(i);
}
 
void solve()
{
    int n,x,y;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        edges[i].clear();
        cycle[i]=0;
        p[i]=0;
        done[i]=0;
    }
    h[0]=-1;
    for (int i=1;i<=n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    done[1]=1;
    h[1]=1;
    bool b=0;
    while (!q.empty())
    {
        x=q.front();
        q.pop();
        for (int i : edges[x])
            if (i!=p[x])
            {
                if (done[i])
                {
                    buildAns(x,i);
                    b=1;
                    break;
                }
                q.push(i);
                done[i]=1;
                p[i]=x;
                h[i]=h[x]+1;
            }
        if (b)
            break;
    }
    ll ans = 1LL * n * (n-1);
    for (int i=1;i<=n;++i)
        done[i]=0;
    for (int i=1;i<=n;++i)
        if (!cycle[i]&&!done[i])
        {
            l=0;
            dfs(i);
            ans-=((1LL*l*(l-1))/2);
        }
    cout<<ans<<"\n";
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