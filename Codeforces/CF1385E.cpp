#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int MAXN = 2e5+7;
int pos[MAXN],incoming[MAXN];
vector<int> outgoing[MAXN];

void solve()
{
    int n,m,t,x,y;
    cin>>n>>m;
    vector<pii> toDo;
    for (int i=1;i<=n;++i)
    {
        outgoing[i].clear();
        incoming[i]=0;
    }
    for (int i=0;i<m;++i)
    {
        cin>>t>>x>>y;
        if (t)
        {
            ++incoming[y];
            outgoing[x].push_back(y);
        }
        else
            toDo.push_back({x,y});
    }
    y=0;t=0;
    stack<int> st;
    for (int i=1;i<=n;++i)
        if (!incoming[i])
            st.push(i);
    while (sz(st))
    {
        x=st.top();
        st.pop();
        ++y;
        pos[x]=++t;
        for (int i : outgoing[x])
        {
            --incoming[i];
            if (!incoming[i])
                st.push(i);
        }
    }
    if (y!=n)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for (int i=1;i<=n;++i)
        for (int j : outgoing[i])
            cout<<i<<" "<<j<<"\n";
    for (pii i : toDo)
    {
        if (pos[i.f]<pos[i.s])
            cout<<i.f<<" "<<i.s<<"\n";
        else
            cout<<i.s<<" "<<i.f<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin>>tests;
    while (tests--)
        solve();
    return 0;
}