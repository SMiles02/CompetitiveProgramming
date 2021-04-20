#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 4e5+1, INF = 1e9;
int p[N];
bitset<N> o;
set<int> s;

array<int,2> f()
{
    if (s.empty())
        return {0,0};
    int x,y;
    array<int,2> a;
    x=*(s.begin());
    y=*(--s.end());
    if (p[x]==y)
    {
        s.erase(s.find(x));
        s.erase(s.find(y));
        a=f();
        if (o[x])
            return {a[0],a[1]+1};
        return {a[0]+1,a[1]};
    }
    s.erase(s.find(x));
    s.erase(s.find(y));
    s.erase(s.find(p[x]));
    s.erase(s.find(p[y]));
    a=f();
    if (o[x]==o[y])
        return {a[0]+1,a[1]+1};
    if (o[x]&&!o[y])
        return {a[0],a[1]+2};
    return {a[0]+2,a[1]};
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y,mn=INF,mx=0;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>x>>y;
        mx=max(mx,min(x,y));
        mn=min(mn,max(x,y));
        p[x]=y;
        p[y]=x;
        o[x]=1;
        s.insert(x);
        s.insert(y);
    }
    if (mn<mx)
    {
        cout<<-1;
        return 0;
    }
    array<int,2> a = f();
    cout<<min(a[0],a[1]);
    return 0;
}