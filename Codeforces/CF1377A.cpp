#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

const int NUM = 1e6+5;
vector<int> edges[NUM];
bool done[NUM];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n=0,u,v;
    freopen("a1.in", "r", stdin);
    while (cin>>u)
    {
        cin>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
        n=max(n,max(u,v));
    }
    vector<int> p;
    for (int i=0;i<=n;++i)
        p.push_back(i);
    shuffle(p.begin(), p.end(), rng);
    queue<int> q;
    for (int i : p)
        if (!done[i])
        {
            done[i]=1;
            q.push(i);
            while (!q.empty())
            {
                v=q.front();
                q.pop();
                cout<<v<<" ";
                for (int j : edges[i])
                    if (!done[j])
                        if ((uniform_int_distribution<int>(1,69)(rng)*uniform_int_distribution<int>(1,42)(rng))%2==0)
                        {
                            done[j]=1;
                            q.push(j);
                        }
            }
            cout<<"\n";
        }
    return 0;
}