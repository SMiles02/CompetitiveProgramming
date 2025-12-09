#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,ans=0;
    cin>>n>>m;
    int a[m],l[m];
    for (int i=0;i<m;++i)
        a[i]=0;
    string g[n+1];
    g[0] = string(m,'*');
    for (int i=1;i<=n;++i)
    {
        stack<int> s,t;
        cin>>g[i];
        for (int j=0;j<m;++j)
        {
            if (g[i][j]=='*')
                a[j]=0;
            else
                ++a[j];
            while (!s.empty()&&a[j]<=a[s.top()])
                s.pop();
            if (s.empty())
                l[j]=-1;
            else
                l[j]=s.top();
            s.push(j);
        }
        for (int j=m-1;j>=0;--j)
        {
            while (!t.empty()&&a[j]<=a[t.top()])
                t.pop();
            if (t.empty())
                ans=max(ans,(m-1-l[j])*a[j]);
            else
                ans=max(ans,(t.top()-1-l[j])*a[j]);
            t.push(j);
        }
    }
    cout<<ans;
    return 0;
}