#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mp = 1e6, N = 404;
ll a[N][2];
bitset<N> done;
int to[N];
vector<int> from[N], store[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y,k,ans=0;
    cin>>n>>x>>y;
    for (int i=1;i<=n;++i)
        cin>>a[i][0]>>a[i][1];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            if (i!=j&&a[j][0]*x<=a[i][0]*mp&&a[i][0]*mp<=a[j][0]*y&&a[j][1]*x<=a[i][1]*mp&&a[i][1]*mp<=a[j][1]*y)
            {
                from[i].push_back(j);
                ++to[j];
            }
    stack<int> s;
    for (int i=1;i<=n;++i)
        if (to[i]==0)
        {
            ++ans;
            store[i].push_back(n+ans);
            s.push(i);
        }
    while (!s.empty())
    {
        k=s.top();
        s.pop();
        bool ok=0;
        for (int i : store[k])
            if (!done[i])
            {
                done[i]=1;
                ok=1;
                break;
            }
        if (!ok)
            ++ans;
        for (int i : from[k])
        {
            store[i].push_back(k);
            if (--to[i]==0)
                s.push(i);
        }
    }
    cout<<ans;
    return 0;
}