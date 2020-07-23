#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x;
    ll ans=0;
    cin>>n>>m;
    priority_queue<int,vector<int>,greater<int>> q;
    deque<int> wait;
    int r[n];
    int w[m+1];
    int a[m+1];
    for (int i=0;i<n;++i)
    {
        cin>>r[i];
        q.push(i);
    }
    for (int i=1;i<=m;++i)
        cin>>w[i];
    for (int i=0;i<2*m;++i)
    {
        cin>>x;
        if (x<0)
            q.push(a[-x]);
        else
            wait.push_back(x);
        if (sz(q)&&sz(wait))
        {
            x=wait.front();
            wait.pop_front();
            ans+=r[q.top()]*w[x];
            a[x]=q.top();
            q.pop();
        }
    }
    cout<<ans;
    return 0;
}