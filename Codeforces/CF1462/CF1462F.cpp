#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

void solve()
{
    int n,ans=0,ct=0,alive=0;
    cin>>n;
    map<int,int> in,out,m,a;
    set<int> s;
    pair<int,int> p[n];
    for (int i=0;i<n;++i)
    {
        cin>>p[i].f>>p[i].s;
        s.insert(p[i].f-1);
        s.insert(p[i].f);
        s.insert(p[i].s);
        s.insert(p[i].s+1);
        ++in[p[i].f];
        ++out[p[i].s+1];
    }
    for (int i : s)
    {
        ct+=in[i];
        alive+=in[i]-out[i];
        m[i]=ct;
        a[i]=alive;
    }
    for (int i=0;i<n;++i)
        ans=max(ans,m[p[i].s]-m[p[i].f-1]+a[p[i].f]-in[p[i].f]);
    cout<<n-ans<<"\n";
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