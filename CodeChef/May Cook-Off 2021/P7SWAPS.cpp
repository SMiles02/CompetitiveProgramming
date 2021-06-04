#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
int a[N], p[N];

void solve()
{
    int n,q,t,x,y;
    cin>>n;
    bool og=1;
    stack<array<int,2>> s; 
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        cin>>p[i];
    cin>>q;
    while (q--)
    {
        cin>>t;
        if (t==3)
        {
            cin>>x;
            cout<<a[x]<<"\n";
        }
        else if (t==1)
        {
            if (og)
            {
                for (int i=1;i<=n;++i)
                    a[p[i]]=i;
                og=0;
            }
            else
            {
                while (!s.empty())
                {
                    swap(a[s.top()[0]],a[s.top()[1]]);
                    s.pop();
                }
            }
        }
        else
        {
            cin>>x>>y;
            swap(a[x],a[y]);
            if (!og)
                s.push({x,y});
        }
    }
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