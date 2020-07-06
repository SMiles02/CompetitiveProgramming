#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

multiset<int> k[200001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,c,d;
    cin>>n>>q;
    int a[n+1];
    int cur[n+1];
    multiset<int> ans;
    multiset<int>::iterator it;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        cin>>x;
        cur[i]=x;
        k[x].insert(a[i]);
    }
    for (int i=1;i<200001;++i)
    {
        if (sz(k[i]))
        {
            ans.insert(*(--(k[i].end())));
        }
    }
    for (int i=0;i<q;++i)
    {
        cin>>c>>d;
        it=ans.lower_bound(*(--(k[cur[c]].end())));
        ans.erase(it);
        it=k[cur[c]].lower_bound(a[c]);
        k[cur[c]].erase(it);
        if (sz(k[cur[c]]))
            ans.insert(*(--(k[cur[c]].end())));
        cur[c]=d;
        if (sz(k[cur[c]]))
        {
            it=ans.lower_bound(*(--(k[cur[c]].end())));
            ans.erase(it);
        }
        k[cur[c]].insert(a[c]);
        ans.insert(*(--(k[cur[c]].end())));
        cout<<*(ans.begin())<<"\n";
    }
    return 0;
}