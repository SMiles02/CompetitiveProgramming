#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
bitset<N*2> d;

struct seg
{
    vector<vector<int>> s;
    seg(int n) : s(n*4,vector<int>(3,0)) {}
    void add(int i, int l, int r, int x, int y)
    {
        if (x<l||r<x)
            return;
        if (l==r)
        {
            ++s[i][y];
            return;
        }
        add(i*2+1,l,l+(r-l)/2,x,y);
        add(i*2+2,l+(r-l)/2+1,r,x,y);
        s[i][0]=s[i*2+1][0]+s[i*2+2][0]+min(s[i*2+1][1],s[i*2+2][2]);
        s[i][1]=s[i*2+2][1]+max(0,s[i*2+1][1]-s[i*2+2][2]);
        s[i][2]=s[i*2+1][2]+max(0,s[i*2+2][2]-s[i*2+1][1]);
    }
    int calc()
    {
        return s[0][0];
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n,ans;
    cin>>n;
    int a[n+1],p[n+1];
    seg s1(N),s2(N);
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        d[a[i]]=1;
    }
    for (int i=1;i<=n*2;++i)
        if (!d[i])
        {
            s1.add(0,1,N,i,2);
            s2.add(0,1,N,N-i,2);
        }
    for (int i=1;i<=n;++i)
    {
        s1.add(0,1,N,a[i],1);
        p[i]=s1.calc();
    }
    p[0]=0;
    ans=p[n];
    for (int i=n;i;--i)
    {
        s2.add(0,1,N,N-a[i],1);
        ans=max(ans,s2.calc()+p[i-1]);
    }
    cout<<ans;
    return 0;
}