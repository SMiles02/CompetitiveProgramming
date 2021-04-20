#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bitset<200001> f;

void solve()
{
    int n,x;
    cin>>n;
    int a[n+1],b[n+1];
    a[0]=b[0]=0;
    for (int i=1;i<=n;++i)
    {
        f[i]=0;
        cin>>a[i];
    }
    set<int> s;
    for (int i=n;i;--i)
    {
        f[a[i]]=1;
        b[i]=a[i];
        if (a[i]==a[i-1])
            a[i]=0;
    }
    vector<int> v;
    for (int i=1;i<=n;++i)
        if (!f[i])
        {
            s.insert(i);
            v.push_back(i);
        }
    x=0;
    for (int i=1;i<=n;++i)
    {
        if (a[i]==0)
            cout<<v[x++]<<" ";
        else
            cout<<a[i]<<" ";
    }
    cout<<"\n";
    --x;
    set<int>::iterator it;
    for (int i=1;i<=n;++i)
    {
        if (a[i]==0)
        {
            it = --s.lower_bound(b[i]);
            cout<<*it<<" ";
            s.erase(it);
        }
        else
            cout<<a[i]<<" ";
    }
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