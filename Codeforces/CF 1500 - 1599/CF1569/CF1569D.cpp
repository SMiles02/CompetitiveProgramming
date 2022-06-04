#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll f(ll x)
{
    return (x*(x-1))/2;
}

void solve()
{
    int n,m,k,a,b,p,q,cur,tmp;
    ll ans=0;
    cin>>n>>m>>k;
    int x[n],y[m];
    set<int> s1,s2;
    for (int i=0;i<n;++i)
    {
        cin>>x[i];
        s1.insert(x[i]);
    }
    for (int i=0;i<m;++i)
    {
        cin>>y[i];
        s2.insert(y[i]);
    }
    vector<array<int,2>> X, Y;
    while (k--)
    {
        cin>>a>>b;
        if (s1.count(a))
        {
            if (!s2.count(b))
                X.push_back({b,a});
        }
        else
            Y.push_back({a,b});
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    if (!X.empty())
    {
        map<int,int> mp;
        p=-1;
        ++mp[X[0][1]];
        while (p+1<m&&y[p+1]<X[0][0])
            ++p;
        q=0;
        while (q+1<sz(X)&&X[q+1][0]==X[0][0])
            ans-=(mp[X[++q][1]]++);
        ans+=f(q+1);
        cur=q+1;
        for (++q;q<sz(X);++q)
        {
            while (p+1<m&&y[p+1]<X[q][0])
            {
                ++p;
                cur=0;
                mp.clear();
            }
            ans-=(mp[X[q][1]]++);
            tmp=1;
            while (q+1<sz(X)&&X[q+1][0]==X[q][0])
            {
                ans-=(mp[X[++q][1]]++);
                ++tmp;
            }
            ans+=f(tmp)+1LL*tmp*cur;
            cur+=tmp;
        }
    }
    if (!Y.empty())
    {
        map<int,int> mp;
        p=-1;
        ++mp[Y[0][1]];
        while (p+1<n&&x[p+1]<Y[0][0])
            ++p;
        q=0;
        while (q+1<sz(Y)&&Y[q+1][0]==Y[0][0])
            ans-=(mp[Y[++q][1]]++);
        ans+=f(q+1);
        cur=q+1;
        for (++q;q<sz(Y);++q)
        {
            while (p+1<n&&x[p+1]<Y[q][0])
            {
                ++p;
                cur=0;
                mp.clear();
            }
            ans-=(mp[Y[q][1]]++);
            tmp=1;
            while (q+1<sz(Y)&&Y[q+1][0]==Y[q][0])
            {
                ans-=(mp[Y[++q][1]]++);
                ++tmp;
            }
            ans+=f(tmp)+1LL*tmp*cur;
            cur+=tmp;
        }
    }
    cout<<ans<<"\n";
}
  
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}