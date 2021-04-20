#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

struct DSU
{
    vector<int> pt,rk;
    DSU(int n) : pt(n+1), rk(n+1, 1)
    {
        for (int i = 0; i < n; ++i)
            pt[i] = i;
    }

    int find(int i)
    {
        return i == pt[i] ? i : pt[i] = find(pt[i]);
    }

    void unite(int i, int j)
    {
        i = find(i);
        j = find(j);
        if (i^j)
        {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
        }
    }
};

int s[200000][18];

int query(int l, int r)
{
    int x = r-l+1;
    while (__builtin_popcount(x)>1)
        x-=x&-x;
    return gcd(s[l+x-1][__lg(x)],s[r][__lg(x)]);
}

void solve()
{
    int n,p,x,y,l,r,m;
    long long ans=0;
    cin>>n>>p;
    DSU dsu(n);
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
    pq.push({p,0,n-1});
    for (int i=0;i<n;++i)
        cin>>s[i][0];
    for (int j=1;j<18;++j)
        for (int i=(1<<j)-1;i<n;++i)
            s[i][j]=gcd(s[i][j-1],s[i-(1<<(j-1))][j-1]);
    for (int i=0;i<n;++i)
    {
        l=0;r=i;
        while (l<r)
        {
            m=l+(r-l)/2;
            if (query(m,i)!=s[i][0])
                l=m+1;
            else
                r=m;
        }
        x=l;
        l=i;r=n-1;
        while (l<r)
        {
            m=l+(r-l)/2+1;
            if (query(i,m)!=s[i][0])
                r=m-1;
            else
                l=m;
        }
        y=l;
        if (x!=y)
            pq.push({s[i][0],x,y});
    }
    array<int,3> a;
    while (!pq.empty())
    {
        a=pq.top();
        pq.pop();
        if (dsu.find(a[1])==dsu.find(a[2]))
            continue;
        for (int j=a[1];j<a[2];++j)
            if (dsu.find(j)!=dsu.find(j+1))
            {
                ans+=a[0];
                dsu.unite(j,j+1);
            }
    }
    cout<<ans<<"\n";
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