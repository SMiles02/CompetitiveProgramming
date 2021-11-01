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
vector<int> dp(4,0);
vector<vector<char>> s;
vector<BIT> bit;

void print()
{
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
            cout<<s[i][j];
        cout<<"\n";
    }
}

ll calc()
{
    ll ans=dp[0];
    if (dp[1]==0&&dp[2]==0&&dp[3]==0)
        return ans;
    if (dp[3]==0&&(dp[1]==0||dp[2]==0))
        return ans+1;
    return ans+1+min(dp[1],dp[2]);
}

void check(int c, int d)
{
    if (s[k][c]=='.')
        return;
    int x,y;
    if (k==1)
        x=0;
    else if (k+1<=n)
        x=(bit[c].query(0,k-1)<k-1)&(s[k+1][c]=='.');
    else
        x=(bit[c].query(0,k-1)<k-1);
    if (k==n)
        y=0;
    else if (k-1>=1)
        y=(bit[c].query(k+1,n+1)<n-k)&(s[k-1][c]=='.');
    else
        y=(bit[c].query(k+1,n+1)<n-k);
    cerr << c << ": " << x << " " << y << "\n";
    dp[2*x+y]+=d;
}

ll solve()
{
    int q,x,y,c,d;
    ll ans=0;
    cin>>n>>m>>k>>q;
    s.resize(n+1,vector<char>(m+1));
    bit.clear();
    for (int i=0;i<4;++i)
        dp[i]=0;
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
        check(i,1);
    while (q--)
    {
        cin>>c>>d;
        check(d,-1);
        if (s[c][d]=='X')
        {
            s[c][d]='.';
            bit[d].update(c,-1);
        }
        else
        {
            s[c][d]='X';
            bit[d].update(c,1);
        }
        check(d,1);
        print();
        for (int i=0;i<4;++i)
            cerr<<dp[i]<<" ";
        cerr<<"\n";
        cerr<<calc()<<"\n";
        ans+=calc();
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