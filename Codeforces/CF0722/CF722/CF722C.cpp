#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    pii p;
    cin>>n;
    ll pre[n+1];
    pre[0]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>pre[i];
        pre[i]+=pre[i-1];
    }
    set<pii> segments;
    multiset<ll> values;
    values.insert(0);
    segments.insert({n,1});
    values.insert(pre[n]);
    for (int i=0;i<n;++i)
    {
        cin>>k;
        //cout<<k<<"!\n";
        p=*(segments.lower_bound({k,0}));
        //cout<<"removing {"<<p.f<<","<<p.s<<"}\n";
        //cout<<"removing "<<*(values.lower_bound(pre[p.f]-pre[p.s-1]))<<"\n";
        segments.erase(segments.lower_bound({k,0}));
        values.erase(values.lower_bound(pre[p.f]-pre[p.s-1]));
        if (p.f==p.s)
        {
            cout<<*(--values.end())<<"\n";
            continue;
        }
        if (k==p.f)
        {
            segments.insert({p.f-1,p.s});
            values.insert(pre[p.f-1]-pre[p.s-1]);
            //cout<<"inserting {"<<p.f-1<<","<<p.s<<"}\n";
            //cout<<"inserting "<<pre[p.f-1]-pre[p.s-1]<<"\n";
        }
        else if (k==p.s)
        {
            segments.insert({p.f,p.s+1});
            values.insert(pre[p.f]-pre[p.s]);
            //cout<<"inserting {"<<p.f<<","<<p.s+1<<"}\n";
            //cout<<"inserting "<<pre[p.f]-pre[p.s]<<"\n";
        }
        else
        {
            segments.insert({p.f,k+1});
            values.insert(pre[p.f]-pre[k]);
            //cout<<"inserting {"<<p.f<<","<<k+1<<"}\n";
            //cout<<"inserting "<<pre[p.f]-pre[k]<<"\n";
            segments.insert({k-1,p.s});
            values.insert(pre[k-1]-pre[p.s-1]);
            //cout<<"inserting {"<<k-1<<","<<p.s<<"}\n";
            //cout<<"inserting "<<pre[k-1]-pre[p.s-1]<<"\n";
        }
        cout<<*(--values.end())<<"\n";
    }
    return 0;
}