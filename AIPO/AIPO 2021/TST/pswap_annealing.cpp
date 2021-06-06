#include <bits/stdc++.h>
#define ll long long
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2507, M = 5007, INF = 1e9, X = 2e9, B = 71, P = 31415, MOD = 1e9+7;
int n, p[N][N*2], blocks[N][B][B], score, newScore, powers[B+10], cDiv[M], cMod[M];
bitset<N> e[N], cur;
double tmp = 50;

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}

int sub(int a, int b)
{
    if (b==0)
        return a;
    return add(a,MOD-b);
}

int mul(int a, int b)
{
    return (1LL*a*b)%MOD;
}

int rnd(int l, int r)
{
    return uniform_int_distribution<int>(l,r)(rng);
}

void tryFlip()
{
    int x = rnd(0,n-1);
    if (cur[x])
        newScore=score-1;
    else
    {
        newScore=score+1;
        for (int i=0;i<n;++i)
            if (e[x][i]&&cur[i])
                --newScore;
    }
    if (newScore>=score||exp((double)(newScore-score)/tmp)>(double)1/rnd(0,X))
    {
        score=newScore;
        if (cur[x])
            cur[x]=0;
        else
        {
            cur[x]=1;
            for (int i=0;i<n;++i)
                if (e[x][i]&&cur[i])
                    cur[i]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    powers[0]=1;
    for (int i=1;i<B+10;++i)
        powers[i]=(1LL*powers[i-1]*P)%MOD;
    int m,x;
    cin>>n>>m;
    for (int i=0;i<M;++i)
    {
        cDiv[i]=i/B;
        cMod[i]=i%B;
    }
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<m;++j)
        {
            cin>>p[i][j];
            blocks[i][cDiv[j]][cMod[j]]=mul(p[i][j],powers[cMod[j]]);
            if (cMod[j])
                blocks[i][cDiv[j]][cMod[j]]=add(blocks[i][cDiv[j]][cMod[j]],blocks[i][cDiv[j]][(cMod[j])-1]);
        }
        for (int j=m;cMod[j];++j)
            blocks[i][cDiv[j]][cMod[j]]=add(blocks[i][cDiv[j]][cMod[j]],blocks[i][cDiv[j]][(cMod[j])-1]);
    }
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
        {
            x=0;
            for (int k=0;k<B&&x<3;++k)
                if (blocks[i][k][B-1]!=blocks[j][k][B-1])
                {
                    x+=(blocks[i][k][0]!=blocks[j][k][0]);
                    for (int l=1;l<B;++l)
                        x+=(sub(blocks[i][k][l],blocks[i][k][l-1])!=sub(blocks[j][k][l],blocks[j][k][l-1]));
                }
            if (x<3)
            {
                e[i][j]=1;
                e[j][i]=1;
            }
        }
    const int iter = 840000;
    double mpl = pow(0.000001/tmp,(double)1/iter);
    for (int i=0;i<iter;++i)
    {
        tmp*=mpl;
        tryFlip();
    }
    //cout<<fixed<<setprecision(10)<<tmp<<"\n";
    cout<<score;
    return 0;
}