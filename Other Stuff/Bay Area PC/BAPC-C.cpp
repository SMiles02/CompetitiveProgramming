#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define a2 array<int,2>
using namespace std;

const int N = 1e5+1;
int n;
bitset<N> done;
vector<a2> edges[N];

bool ok(int k)
{
    done.reset();
    queue<int> q;
    done[1]=1;
    q.push(1);
    int x;
    while (!q.empty())
    {
        x=q.front();
        q.pop();
        for (auto i : edges[x])
            if (!done[i[0]]&&k%i[1]==0)
            {
                q.push(i[0]);
                done[i[0]]=1;
            }
    }
    if (done[n])
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,x,y,z;
    cin>>n>>m;
    while (m--)
    {
        cin>>x>>y>>z;
        edges[x].push_back({y,z});
        edges[y].push_back({x,z});
    }
    for (int i=1;1;++i)
    {
        x=i;
        for (int j : {2,3,5,7,11,13})
            while (x%j==0)
                x/=j;
        if (x==1&&ok(i))
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}