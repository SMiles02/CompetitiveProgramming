#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct seg {
    int n;
    vector<int> bit;
    seg(int n) : n(n) {bit.resize(n+1,0);}
    void update(int i, int d)
    {
        while (i<=n)
        {
            bit[i]+=d;
            i+=(i&-i);
        }
    }
    int prefix(int i)
    {
        int ans=0;
        while (i)
        {
            ans+=bit[i];
            i-=(i&-i);
        }
        return ans;
    }
    int query(int l, int r) {
        return prefix(r) - prefix(l-1);
    }
};

const int X = 2e9;

double rnd()
{
    return double(rng()%X)/X;
}

int to[2][101],tin[2][101],tout[2][101],a[2][101],ti;
vector<int> edges[2][101];
bitset<101> picked;

void dfs(int c, int j)
{
    tin[j][c]=++ti;
    for (int i : edges[j][c])
        dfs(i,j);
    tout[j][c]=ti;
}

int main()
{
    int n,x,y,start=clock();
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<2;++i)
    {
        for (int j=1;j<n;++j)
        {
            cin>>x>>y;
            edges[i][x].push_back(y);
            ++to[i][y];
        }
        for (int j=1;j<=n;++j)
            cin>>a[i][j];
    }
    for (int i=1;i<=n;++i)
        for (int j=0;j<2;++j)
            if (to[j][i]==0)
            {
                ti=0;
                dfs(i,j);
            }
    seg t1(n),t2(n);
    for (int i=1;i<=n;++i)
    {
        picked[i]=1;
        t1.update(tin[0][i],1);
        t2.update(tin[1][i],1);
    }
    int score=n,newScore;
    bool ok;
    double t = 50;
    while ((clock()-start)/double(CLOCKS_PER_SEC)<=0.45)
    {
        t*=0.999995;
        x = uniform_int_distribution<int>(1,n)(rng);
        ok=1;
        //cout<<"try changing "<<x<<"\n";
        if (picked[x])
        {
            picked[x]=0;
            newScore=score-1;
            t1.update(tin[0][x],-1);
            t2.update(tin[1][x],-1);
        }
        else
        {
            picked[x]=1;
            newScore=score+1;
            t1.update(tin[0][x],1);
            t2.update(tin[1][x],1);
        }
        for (int i=1;i<=n;++i)
            if (t1.query(tin[0][i],tout[0][i])<a[0][i])
            {
                //cout<<"first: "<<i<<" doesn't approve\n";
                ok=0;
            }
        for (int i=1;i<=n;++i)
            if (t2.query(tin[1][i],tout[1][i])<a[1][i])
            {
                //cout<<"second: "<<i<<" doesn't approve\n";
                ok=0;
            }
        if (ok&&(newScore<score||rnd()<exp((score-newScore)/t)))
        {
            //cout<<"change accepted\n";
            score=newScore;
        }
        else
        {
            //cout<<"change not accepted\n";
            if (picked[x])
            {
                picked[x]=0;
                t1.update(tin[0][x],-1);
                t2.update(tin[1][x],-1);
            }
            else
            {
                picked[x]=1;
                t1.update(tin[0][x],1);
                t2.update(tin[1][x],1);
            }
        }
        // cout<<score<<"\n";
        // for (int i=1;i<=n;++i)
        //     if (picked[i])
        //         cout<<i<<" ";
        // cout<<"\n";
    }
    //cout<<fixed<<setprecision(10)<<t<<"\n";
    cout<<score<<"\n";
    for (int i=1;i<=n;++i)
        if (picked[i])
            cout<<i<<" ";
    return 0;
}