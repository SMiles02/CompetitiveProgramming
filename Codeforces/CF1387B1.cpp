#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int eC[N], ans[N];
long long cost;
vector<int> e[N];
bitset<N> done;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
        ans[i]=i;
    }
    ans[n]=n;
    stack<int> s;
    for (int i=1;i<=n;++i)
    {
        eC[i]=e[i].size();
        if (eC[i]==1)
            s.push(i);
    }
    while (!s.empty())
    {
        x=s.top();
        s.pop();
        done[x]=1;
        for (int i : e[x])
            if (!done[i])
            {
                if (--eC[i]==1)
                    s.push(i);
                if (ans[x]!=x)
                    continue;
                cost+=2;
                swap(ans[x],ans[i]);
            }
    }
    for (int i=1;i<=n;++i)
        if (ans[i]==i)
        {
            cost+=2;
            swap(ans[i],ans[e[i][0]]);
        }
    cout<<cost<<"\n";
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}