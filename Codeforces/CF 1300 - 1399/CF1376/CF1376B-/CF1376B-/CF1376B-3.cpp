#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int NUM=200000;
int ttt=0,n,l=NUM,r=0;
vector<int> edges[NUM+1];
vector<int> p;
bool done[NUM+1];
bool ans[NUM+1];
bool final[NUM+1];
vector<int> numOfE[NUM+1];

bool check()
{
    int cor=0;
    for (int i=l;i<=r;++i)
    {
        shuffle(numOfE[i].begin(), numOfE[i].end(), rng);
        for (int j : numOfE[i])
            if (!done[j])
            {
                done[j]=1;
                ans[j]=1;
                ++cor;
                for (int k : edges[j])
                    done[k]=1;
            }
    }
    if (cor>2800)
    {
        cout<<cor<<"\n";
        for (int i=1;i<=n;++i)
            cout<<ans[i]<<" ";
        return 1;
    }
    if (ttt<cor)
    {
        ttt=cor;
        for (int i=1;i<=n;++i)
            final[i]=ans[i];
    }
    ttt=max(ttt,cor);
    for (int i=1;i<=n;++i)
    {
        ans[i]=0;
        done[i]=0;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,a,b,dd=400000;
    freopen("b1.in", "r", stdin);
    cin>>n>>m;
    while (m--)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i=1;i<=n;++i)
    {
        numOfE[sz(edges[i])].push_back(i);
        l=min(sz(edges[i]),l);
        r=max(sz(edges[i]),r);
    }
    while (dd--)
        if (check())
            return 0;
    cout<<"You got nothing...\n";
    cout<<"Only ";
    cout<<ttt<<"\n";
    for (int i=1;i<=n;++i)
        cout<<final[i]<<" ";
    return 0;
}