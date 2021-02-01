#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

set<int> s[1000001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,n,k,x,cur;
    bool ok;
    cin>>m;
    for (int i=1;i<=m;++i)
    {
        cin>>k;
        s[k].insert(i);
    }
    cin>>n;
    while (n--)
    {
        cin>>k;
        cur=0;
        ok=1;
        while (k--)
        {
            cin>>x;
            if (s[x].upper_bound(cur)==s[x].end())
                ok=0;
            else
                cur=*(s[x].upper_bound(cur));
        }
        if (ok)
            cout<<"TAK\n";
        else
            cout<<"NIE\n";
    }
    return 0;
}