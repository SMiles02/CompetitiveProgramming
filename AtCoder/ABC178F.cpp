#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int maxn = 2e5;
int n,a[maxn],b[maxn],c[maxn],w,x,y,z,k,l;

bool ok()
{
    for (int i=0;i<n;++i)
        if (a[i]==c[i])
            return 0;
    cout<<"Yes\n";
    for (int i=0;i<n;++i)
        cout<<c[i]<<" ";
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    set<int> s;
    map<int,int> m;
    map<int,vector<int>> v;
    priority_queue<pii> p;
    priority_queue<pii,vector<pii>, greater<pii>> q;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        s.insert(a[i]);
        v[a[i]].push_back(i);
        ++m[a[i]];
    }
    for (int i : s)
        p.push({m[i],i});
    s.clear();
    m.clear();
    for (int i=0;i<n;++i)
    {
        cin>>b[i];
        s.insert(b[i]);
        ++m[b[i]];
    }
    for (int i : s)
        q.push({m[i],i});
    while (!p.empty())
    {
        w=p.top().f;x=p.top().s;
        p.pop();
        if (w>1)
            p.push({w-1,x});
        y=q.top().f;z=q.top().s;
        q.pop();
        if (x!=z)
        {
            c[v[x].back()]=z;
            v[x].pop_back();
            if (y>1)
                q.push({y-1,z});
        }
        else if (sz(q))
        {
            k=q.top().f;l=q.top().s;
            q.pop();
            c[v[x].back()]=l;
            v[x].pop_back();
            q.push({y,z});
            if (k>1)
                q.push({k-1,l});
        }
        else
        {
            cout<<"No";
            return 0;
        }
    }
    if (ok())
        return 0;
    cout<<"No";
    return 0;
}
