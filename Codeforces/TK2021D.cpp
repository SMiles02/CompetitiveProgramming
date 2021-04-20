#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5+6, INF = 1e9+7;
set<int> involve[N], s;
set<array<int,2>> p;

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

void remAll(array<int,2> a)
{
    if (p.find(a)!=p.end())
        p.erase(p.find(a));
    if (involve[a[0]].find(a[1])!=involve[a[0]].end())
        involve[a[0]].erase(involve[a[0]].find(a[1]));
    if (involve[a[1]].find(a[0])!=involve[a[1]].end())
        involve[a[1]].erase(involve[a[1]].find(a[0]));
}

void addP(int x, int y)
{
    involve[x].insert(y);
    involve[y].insert(x);
    p.insert({x,y});
}

void solve()
{
    int n,c=0,x;
    cin>>n;
    int a[n+1];
    array<int,2> b;
    vector<int> ans;
    s.clear();
    p.clear();
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        involve[i].clear();
        s.insert(i);
    }
    for (int i=1;i<n;++i)
        if (gcd(a[i],a[i+1])==1)
            addP(i,i+1);
    if (gcd(a[n],a[1])==1)
        addP(n,1);
    while (!p.empty())
    {
        if (p.upper_bound({c,INF})==p.end())
        {
            c=0;
            continue;
        }
        b=*(p.upper_bound({c,INF}));
        c=b[1];
        //p.erase(p.upper_bound({c,INF}));
        while (!involve[b[1]].empty())
        {
            x=*(involve[b[1]].begin());
            remAll({x,b[1]});
            remAll({b[1],x});
        }
        if (s.find(b[1])!=s.end())
            s.erase(s.find(b[1]));
        ans.push_back(b[1]);
        if (s.find(b[0])!=s.end())
        {
            if (s.upper_bound(b[0])==s.end())
            {
                if (gcd(a[b[0]],a[*(s.begin())])==1)
                    addP(b[0],*(s.begin()));
            }
            else if (gcd(a[b[0]],a[*(s.upper_bound(b[0]))])==1)
                addP(b[0],*(s.upper_bound(b[0])));
        }
    }
    cout<<sz(ans)<<" ";
    for (int i : ans)
        cout<<i<<" ";
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