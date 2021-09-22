#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5+7;
int n,m,k,t,ans;
vector<int> v[N], f[N];
stack<int> s;

void check(int x)
{
    if (sz(f[x])>1)
    {
        ++ans;
        s.push(x);
    }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i)
    {
        cin>>k;
        while (k--)
        {
            cin>>t;
            v[i].push_back(t);
        }
        f[v[i].back()].push_back(i);
    }
    for (int i=1;i<=n;++i)
        check(i);
    while (!s.empty())
    {
        k=s.top();
        s.pop();
        for (int i : f[k])
        {
            v[i].pop_back();
            if (!v[i].empty())
            {
                f[v[i].back()].push_back(i);
                check(v[i].back());
            }
        }
        f[k].clear();
    }
    if (ans==n)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}