#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int ans[200002];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    multiset<pair<int,int>> m;
    multiset<pair<int,int>>::iterator it;
    for (int i=n;i;--i)
    {
        while (sz(m))
        {
            it=m.end();
            --it;
            if ((*it).first<=a[i])
                break;
            ans[(*it).second]=i;
            m.erase(it);
        }
        m.insert({a[i],i});
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}