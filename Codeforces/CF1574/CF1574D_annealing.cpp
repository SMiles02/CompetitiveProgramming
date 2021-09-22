#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// note: doesn't work :holyfuck:

const int N = 1e5+1, M = 11, INF = 1e9, X = 2*INF, MOD = 1e9+7;
int n, q, l[M], x, y, sG, b1, b2, ansVal = -1e9, score, newScore;
vector<int> cfg, ans;
vector<vector<int>> a;
double t=50; //starting temperature
set<array<int,2>> s;

double rnd()
{
    return double(rng()%X)/X;
}

int RNG(int x, int y)
{
    return uniform_int_distribution<int>(x,y)(rng);
}

int get_val(int base, vector<int>& v)
{
    ll rtn = 0;
    for (int i : v)
    {
        rtn*=base;
        rtn+=i;
        rtn%=MOD;
    }
    return rtn;
}

void get_score()
{
    newScore=0;
    for (int i=0;i<n;++i)
        newScore+=a[i][cfg[i]];
    if (s.count({get_val(b1,cfg),get_val(b2,cfg)}))
        newScore-=INF;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    b1=RNG(1e5+7,1e7+7);
    b2=RNG(1e5+7,1e7+7);
    a.resize(n);
    cfg.resize(n);
    ans.resize(n);
    vector<int> w(n), g;
    for (int i=0;i<n;++i)
    {
        cin>>l[i];
        if (l[i]>1)
            g.push_back(i);
        a[i].resize(l[i]+1);
        for (int j=1;j<=l[i];++j)
            cin>>a[i][j];
    }
    sG=sz(g);
    cin>>q;
    while (q--)
    {
        for (int i=0;i<n;++i)
            cin>>w[i];
        s.insert({get_val(b1,w),get_val(b2,w)});
    }
    for (int i=0;i<n;++i)
        ans[i]=cfg[i]=RNG(1,l[i]);
    if (sG==0)
    {
        for (int i : ans)
            cout<<i<<" ";
        return 0;
    }
    ansVal=score=newScore;
    int iterations = 39'000'000;
    double mpl = pow((1e-5)/t,(double)1/iterations);
    for (int i=0;i<iterations;++i)
    {
        t*=mpl;
        x=g[RNG(0,sG-1)];
        y=RNG(0,2);
        if (y==0||y==1)
            y=1;
        else
            y=-1;
        if (cfg[x]==1)
            y=1;
        else if (cfg[x]==l[x])
            y=-1;
        cfg[x]+=y;
        get_score();
        if (newScore>=score||rnd()<exp((newScore-score)/t))
        {
            score=newScore;
            if (score>ansVal)
            {
                ansVal=score;
                for (int j=0;j<n;++j)
                    ans[j]=cfg[j];
            }
        }
        else
            cfg[x]-=y;
    }
    //cerr<<ansVal<<"\n";
    for (int i : ans)
        cout<<i<<" ";
    return 0;
}