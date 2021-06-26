#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[200000];

void solve()
{
    int n,x,y;
    pair<int,int> p;
    cin>>n;
    multiset<pair<int,int>> m;
    multiset<pair<int,int>>::iterator it;
    m.insert({n,0});
    for (int i=1;i<=n;++i)
    {
        it=m.end();
        --it;
        p=*it;
        x=p.first;
        y=-p.second;
        m.erase(it);
        if (x%2)
        {
            a[y+x/2]=i;
            if (x>1)
            {
                m.insert({x/2,-(y)});
                m.insert({x/2,-(y+x/2+1)});
            }
        }
        else
        {
            a[y+x/2-1]=i;
            if (x==2)
                m.insert({1,-(y+x/2)});
            else
            {
                m.insert({x/2-1,-(y)});
                m.insert({x/2,-(y+x/2)});
            }
        }
    }
    for (int i=0;i<n;++i)
        cout<<a[i]<<" ";
    cout<<"\n";
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