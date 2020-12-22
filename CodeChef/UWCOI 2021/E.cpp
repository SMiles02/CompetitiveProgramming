#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

vector<int> v[20];

void solve()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<20;++i)
        v[i].clear();
    for (int i=0;i<(1<<n);++i)
        v[__builtin_popcount(i)].push_back(i);
    priority_queue<pii> q;
    pii a,b,c,d,e;
    for (int i=0;i<20;++i)
        if (sz(v[i]))
            q.push({sz(v[i]),i});
    if (n==3&&k==5)
    {
        cout<<"0 1\n1 3\n3 7\n7 5\n5 0\n";
        return;
    }
    cout<<q.size()<<"\n";
    if (k%3==2)
    {
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        c=q.top();
        q.pop();
        d=q.top();
        q.pop();
        e=q.top();
        q.pop();
        cout<<v[a.s].back()<<" "<<v[b.s].back()<<"\n";
        cout<<v[b.s].back()<<" "<<v[c.s].back()<<"\n";
        cout<<v[c.s].back()<<" "<<v[d.s].back()<<"\n";
        cout<<v[d.s].back()<<" "<<v[e.s].back()<<"\n";
        cout<<v[e.s].back()<<" "<<v[a.s].back()<<"\n";
        v[a.s].pop_back();
        v[b.s].pop_back();
        v[c.s].pop_back();
        v[d.s].pop_back();
        v[e.s].pop_back();
        --a.f;
        --b.f;
        --c.f;
        --d.f;
        --e.f;
        q.push(a);
        q.push(b);
        q.push(c);
        q.push(d);
        q.push(e);
        k-=5;
    }
    if (k%3==1)
    {
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        c=q.top();
        q.pop();
        d=q.top();
        q.pop();
        cout<<v[a.s].back()<<" "<<v[b.s].back()<<"\n";
        cout<<v[b.s].back()<<" "<<v[c.s].back()<<"\n";
        cout<<v[c.s].back()<<" "<<v[d.s].back()<<"\n";
        cout<<v[d.s].back()<<" "<<v[a.s].back()<<"\n";
        v[a.s].pop_back();
        v[b.s].pop_back();
        v[c.s].pop_back();
        v[d.s].pop_back();
        --a.f;
        --b.f;
        --c.f;
        --d.f;
        q.push(a);
        q.push(b);
        q.push(c);
        q.push(d);
        k-=4;
    }
    while (k)
    {
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        c=q.top();
        q.pop();
        cout<<v[a.s].back()<<" "<<v[b.s].back()<<"\n";
        cout<<v[b.s].back()<<" "<<v[c.s].back()<<"\n";
        cout<<v[c.s].back()<<" "<<v[a.s].back()<<"\n";
        //cout<<"test\n";return;
        v[a.s].pop_back();
        v[b.s].pop_back();
        v[c.s].pop_back();
        --a.f;
        --b.f;
        --c.f;
        q.push(a);
        q.push(b);
        q.push(c);
        k-=3;
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