#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
using namespace std;

void solve()
{
    int n,m,a,b,c,d;
    bool diag=0,side=0;
    cin>>n>>m;
    set<pair<pii,pii>> s;
    while (n--)
    {
        cin>>a>>b;
        cin>>c>>d;
        s.insert({{a,b},{c,d}});
        if (b==c)
            diag=1;
        if (s.find({{a,c},{b,d}})!=s.end())
            side=1;
    }
    if (m&1)
    {
        cout<<"NO\n";
        return;
    }
    if (m==2)
    {
        if (diag)
        {
            cout<<"YES\n";
            return;
        }
    }
    if (side&&diag)
    {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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