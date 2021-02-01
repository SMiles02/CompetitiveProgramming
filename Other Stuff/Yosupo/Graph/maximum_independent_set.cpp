#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int NUM = 40, INF = 1e9, X = 2*INF;
vector<int> edges[NUM];
int n,score,k,newScore;
bool ans[NUM],newAns[NUM];

double rnd()
{
    return double(rng()%X)/X;
}

void buildFirst()
{
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
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
    for (int i=0;i<n;++i)
        b[i]=a[i];
}

void makeNew()
{
    newScore=score;
    copyAtoB(ans,newAns);
    k=uniform_int_distribution<int>(0,n-1)(rng);
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
    int m,a,b,start=clock();
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    while (m--)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    buildFirst();
    double t=50;
    while ((clock()-start)/double(CLOCKS_PER_SEC)<4.9)
    {
        t*=0.99999951;
        makeNew();
        if (newScore>=score||rnd()<exp((newScore-score)/t))
        {
            copyAtoB(newAns,ans);
            score=newScore;
        }
    }
    //cout<<fixed<<setprecision(10)<<t<<"\n";
    cout<<score<<"\n";
    for (int i=0;i<n;++i)
        if (ans[i])
            cout<<i<<" ";
        //cout<<ans[i]<<" ";
    return 0;
}