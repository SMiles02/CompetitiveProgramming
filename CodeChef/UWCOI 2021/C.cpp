#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pli pair<ll,int>
#define f first
#define s second
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    ll a[n+1];
    set<pli> s;
    pli p,q;
    for (int i=0;i<=n;++i)
    {
        cin>>a[i];
        if (a[i]>0)
            s.insert({a[i],i});
    }
    for (int i=0;i<n;++i)
    {
        p=*(--s.end());
        s.erase(--s.end());
        if (p.f>=k)
        {
            cout<<p.s<<" "<<k<<" ";
            if (p.s==0)
                cout<<"1 0\n";
            else
                cout<<"0 0\n";
            if (p.f-k>0)
                s.insert({p.f-k,p.s});
        }
        else
        {
            q=*(--s.upper_bound({k-p.f,0}));
            s.erase(s.find(q));
            //cout<<q.f<<" "<<q.s<<"!!!\n";
            cout<<p.s<<" "<<p.f<<" "<<q.s<<" "<<min(q.f,k-p.f)<<"\n";
            if (q.f-k+p.f>0)
                s.insert({q.s,q.f-k+p.f});
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