#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int NUM = 200000, INF = 1e9, X = 2*INF;
vector<int> edges[NUM+1];
int n,score,k,newScore;
bool ans[NUM+1],newAns[NUM+1];

double rnd()
{
    return double(rng()%X)/X;
}

void buildFirst()
{
    vector<int> v(NUM);
    iota(v.begin(), v.end(), 1);
    shuffle(v.begin(), v.end(), rng);
    bool ok;
    for (int i : v)
    {
        ok=1;
        for (int j : edges[i])
            if (ans[j])
            {
                ok=0;
                break;
            }
        if (ok)
        {
            ++score;
            ans[i]=1;
        }
    }
}

void copyAtoB(bool a[], bool b[])
{
    for (int i=1;i<=n;++i)
        b[i]=a[i];
}

void makeNew()
{
    newScore=score;
    copyAtoB(ans,newAns);
    k=uniform_int_distribution<int>(1,n)(rng);
    if (newAns[k])
        --newScore;
    else
    {
        ++newScore;
        for (int i : edges[k])
            if (newAns[i])
            {
                --newScore;
                newAns[i]=0;
            }
    }
    newAns[k]^=1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,a,b;
    freopen("b3.in", "r", stdin);
    cin>>n>>m;
    while (m--)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    buildFirst();
    double t=50;
    for (int i=0;i<10000000;++i)
    {
        t*=0.9999;
        makeNew();
        if (newScore>=score||rnd()<exp((newScore-score)/t))
        {
            copyAtoB(newAns,ans);
            score=newScore;
        }
    }
    cout<<fixed<<setprecision(10)<<t<<"\n";
    cout<<score<<"\n";
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}