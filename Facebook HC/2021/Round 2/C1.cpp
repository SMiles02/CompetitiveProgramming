//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

struct BIT {
    int n,rtn;
    vector<int> bit;
    BIT(int n) : n(n), bit(n+1,0) {}
    void update(int x, int d) { for (int i=x;i<=n;i+=i&-i) bit[i]+=d; }
    int query(int x) {
        rtn=0;
        for (int i=x;i;i-=i&-i) rtn+=bit[i];
        return rtn;
    }
    int query(int x, int y) {
        if (x==0)
            return query(y);
        return query(y) - query(x-1);
    }
};

int n,m,k;

ll solve()
{
    int x,y,c,d;
    cin>>n>>m>>k;
    ll ans=0,cur;
    vector<vector<char>> s(n+1,vector<char>(m+1));
    vector<BIT> bit;
    BIT b(n+1);
    for (int i=0;i<=m;++i)
        bit.push_back(b);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        {
            cin>>s[i][j];
            if (s[i][j]=='X')
                bit[j].update(i,1);
        }
    for (int i=1;i<=m;++i)
        ans+=(s[k][i]=='X');
    for (int i=1;i<=n;++i)
    {
        cur=0;
        for (int j=1;j<=m;++j)
        {
            if (bit[j].query(0,min(n,k+i))>=k)
                ++cur;
            else if (k+i<=n&&s[k+i][j]=='X')
                ++cur;
        }
        ans=min(ans,cur+i);
    }
    for (int i=1;i<=n;++i)
    {
        cur=0;
        for (int j=1;j<=m;++j)
        {
            if (bit[j].query(max(1,k-i),n+1)>=n-k+1)
                ++cur;
            else if (k-i>=1&&s[k-i][j]=='X')
                ++cur;
        }
        ans=min(ans,cur+i);
    }
    return ans;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    for (int i=1;i<=t;++i)
        cout<<"Case #"<<i<<": "<<solve()<<"\n";
    return 0;
}