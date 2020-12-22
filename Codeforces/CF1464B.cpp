#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mn = 1e5+69, INF = 1e9, XY = 2*INF;
vector<int> v;
int n,x,y,K,k,bit[mn];
string s;
bitset<mn> val;
ll score,newScore,X[mn],Y[mn];
double t=50;

double rnd()
{
    return double(rng()%XY)/XY;
}

void update(int i, int d)
{
    while (i<mn)
    {
        bit[i]+=d;
        i+=(i&-i);
    }
}

int pre(int i)
{
    int rV=0;
    while (i)
    {
        rV+=bit[i];
        i-=(i&-i);
    }
    return rV;
}

int query(int l, int r)
{
    return pre(r) - pre(l-1);
}

void buildFirst()
{
    for (int i=1;i<=n;++i)
        if (s[i]=='?')
            v.push_back(i);
    K=sz(v);int ct=0;
    for (int i=1;i<=n;++i)
    {
        if (s[i]=='?')
        {
            if (rnd()<=0.5)
            {
                s[i]='1';
                val[ct]=1;
            }
            ++ct;
        }
        if (s[i]=='1')
        {
            update(i,1);
            score+=X[i-1-pre(i-1)];
        }
        else
            score+=Y[pre(i-1)];
    }
}

void makeNew()
{
    newScore=score;
    k=uniform_int_distribution<int>(0,K-1)(rng);
    if (val[k]==1)
    {
        newScore-=X[v[k]-1-pre(v[k]-1)];
        newScore-=Y[n-v[k]-query(v[k]+1,n+1)];
        newScore+=Y[pre(v[k]-1)];
        newScore+=X[query(v[k]+1,n+1)];
        if (newScore<score||rnd()<exp((score-newScore)/t))
        {
            val[k]=0;
            update(v[k],-1);
            score=newScore;
        }
    }
    else
    {
        newScore-=X[query(v[k]+1,n+1)];
        newScore-=Y[pre(v[k]-1)];
        newScore+=Y[n-v[k]-query(v[k]+1,n+1)];
        newScore+=X[v[k]-1-pre(v[k]-1)];
        if (newScore<score||rnd()<exp((score-newScore)/t))
        {
            val[k]=1;
            update(v[k],1);
            score=newScore;
        }
    }
}

int main()
{
    double start = clock();
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s;
    cin>>x>>y;
    n=sz(s);
    s="|"+s;
    for (int i=1;i<mn;++i)
    {
        X[i]=X[i-1]+x;
        Y[i]=Y[i-1]+y;
    }
    buildFirst();
    if (K==0)
    {
        cout<<score;
        return 0;
    }
    if (K==n||K==n-1)
    {
        cout<<0;
        return 0;
    }
    while ((clock()-start)/double(CLOCKS_PER_SEC)<=0.96)
    {
        t*=0.999997;
        makeNew();
    }
    //cout<<fixed<<setprecision(10)<<t<<"\n";
    cout<<score;
    //if this passes, kostia orz
    //fuck me fuck me fuck me fuck me
    //ok i hate life
    //fuck me
    //f
    //u
    //c
    //k
    //
    //m
    return 0;
}