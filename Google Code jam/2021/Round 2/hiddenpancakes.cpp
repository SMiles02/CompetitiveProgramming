#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5+7, mod = 1e9+7;
int to[N], f[N], sub[N];
vector<int> from[N], e[N];

int mul(int a, int b)
{
    return (1LL*a*b)%mod;
}

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int C(int n, int k)
{
    return mul(f[n],binpow(mul(f[k],f[n-k]),mod-2));
}

void dfsSize(int c)
{
    sub[c]=1;
    for (int i : e[c])
    {
        dfsSize(i);
        sub[c]+=sub[i];
    }
}

int dfs(int c)
{
    int ans=1, k=sub[c]-1;
    for (int i : e[c])
    {
        ans=mul(ans,mul(C(k,sub[i]),dfs(i)));
        //cout<<c<<" "<<i<<": C("<<k<<","<<sub[i]<<")\n";
        k-=sub[i];
    }
    //cout<<c<<": "<<ans<<"\n";
    return ans;
}

int solve()
{
    int n,r,x;
    cin>>n;
    int a[n];
    stack<int> s;
    for (int i=0;i<n;++i)
    {
        e[i].clear();
        from[i].clear();
        to[i]=0;
        cin>>a[i];
    }
    if (a[0]!=1)
        return 0;
    s.push(0);
    for (int i=1;i<n;++i)
    {
        if (a[i]>a[i-1]+1)
            return 0;
        if (a[i]==a[i-1]+1)
        {
            ++to[i];
            from[i-1].push_back(i);
        }
        else
        {
            while (sz(s)+1>a[i])
            {
                ++to[s.top()];
                from[i].push_back(s.top());
                s.pop();
            }
            if (!s.empty())
            {
                ++to[i];
                from[s.top()].push_back(i);
            }
        }
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i=0;i<n;++i)
        if (to[i]==0)
        {
            s.push(i);
            r=i;
        }
    while (!s.empty())
    {
        x=s.top();
        s.pop();
        for (int i : from[x])
            if (--to[i]==0)
            {
                e[x].push_back(i);
                s.push(i);
            }
    }
    dfsSize(r);
    return dfs(r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    f[0]=1;
    for (int i=1;i<N;++i)
        f[i]=mul(f[i-1],i);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cout<<"Case #"<<i<<": ";
        cout<<solve()<<"\n";
    }
    return 0;
}