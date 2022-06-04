//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 1e9+7;
int n;
vector<deque<ll>> v;

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int mul(int a, int b) { return (1LL*a*b)%MOD; }

int binpow(int a, ll b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

vector<int> merge(vector<int>& b, vector<int> l, vector<int> r)
{
    vector<int> dp(6);
    for (int i=0;i<6;++i)
        for (int j=0;j<6;++j)
            if (i!=j&&(i^1)!=j)
                for (int k=0;k<6;++k)
                    if (i!=k&&(i^1)!=k)
                        dp[i]=add(dp[i],mul(b[i],mul(l[j],r[k])));
    return dp;
}

vector<int> normal(int X)
{
    vector<int> dp(6);
    if (X==1)
        dp[0]=1;
    else
        dp[0]=binpow(4,(1LL<<n)-2);
    for (int i=1;i<6;++i)
        dp[i]=dp[i-1];
}

vector<int> solve(int k, int l, int r, ll x)
{
    cerr<<k<<" "<<l<<" "<<r<<" "<<x<<"\n";
    int bL, bR, bM;
    vector<int> dp(6), b(6,1), L, R;
    if (v[l][k+1]==0)
    {
        for (int i=0;i<6;++i)
            if (i!=v[l].back())
                b[i]=0;
        if (++l>r)
        {
            if (k+1==n)
                return b;
            L=normal(n-k);
            R=normal(n-k);
            return merge(b,L,R);
        }
    }
    if (v[l][k+1]==v[r][k+1])
    {
        if (v[l][k+1]==x*2)
            L=solve(k+1,l,r,x*2);
        else
            L=solve(k+1,l,r,x*2+1);
        R=normal(n-k);
        return merge(b,L,R);
    }
    bL=l;
    bR=r;
    while (bL<bR)
    {
        bM=bL+(bR-bL)/2+1;
        if (v[bM][l+1]==x*2)
            bL=bM;
        else
            bR=bM-1;
    }
    L=solve(k+1,l,bM,x*2);
    R=solve(k+1,bM+1,r,x*2+1);
    return merge(b,L,R);
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m;
    ll k;
    string s;
    cin>>n;
    cin>>m;
    map<char,int> mp;
    mp['w']=0;
    mp['y']=1;
    mp['g']=2;
    mp['b']=3;
    mp['r']=4;
    mp['o']=5;
    for (int i=0;i<m;++i)
    {
        cin>>k>>s;
        deque<ll> d = {k};
        while (d.front()>1)
            d.push_front(d.front()/2);
        while (sz(d)<=n)
            d.push_back(0);
        d.push_back(mp[s[0]]);
        v.push_back(d);
    }
    sort(v.begin(), v.end());
    vector<int> dp = solve(0,0,m-1,1);
    int ans=0;
    for (int i : dp)
        ans=add(ans,i);
    cout<<ans;
    return 0;
}