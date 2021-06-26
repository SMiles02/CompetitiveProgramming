#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define a2 array<int,2>
#define p pair<int,double>
#define int ll
using namespace std;

const int N = 1e5;
double b[N],c[N];

ll find_inversions(int l, int r)
{
    if (l==r)
        return 0;
    int m=l+((r-l)>>1),x=l,y=m+1;
    ll ans=find_inversions(l,m)+find_inversions(m+1,r);
    for (int i=l;i<=r;++i)
    {
        if (x>m)
            c[i]=b[y++];
        else if (y>r)
            c[i]=b[x++];
        else if (b[x]>b[y])
        {
            c[i]=b[y++];
            ans+=m-x+1;
        }
        else
            c[i]=b[x++];
    }
    for (int i=l;i<=r;++i)
        b[i]=c[i];
    return ans;
}

double sq(double A)
{
    return A*A;
}

double dist(double A, double B, double C, double D)
{
    return sq(A-C)+sq(B-D);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y,c,d,e,f,g,t;
    ll ans=0;
    cin>>n>>x>>y;
    set<a2> s;
    map<a2,vector<p>> m;
    while (n--)
    {
        cin>>c>>d>>t;
        g=gcd(abs(c-x),abs(d-y));
        e=(c-x)/g;
        f=(d-y)/g;
        s.insert({e,f});
        m[{e,f}].push_back({abs(c-x),dist(c,d,x,y)/(1LL*t*t)});
    }
    for (auto i : s)
    {
        sort(m[i].begin(), m[i].end());
        for (int j=0;j<sz(m[i]);++j)
            b[j]=m[i][j].second;
        ans+=find_inversions(0,sz(m[i])-1);
    }
    cout<<ans;
    return 0;
}