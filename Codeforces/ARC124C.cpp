#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int NUM = 52, INF = 1e9, X = 2*INF;
int n, k;
ll score, newScore;
int a[NUM][2];
double t = 50;
bitset<NUM> ans, newAns;

int gcd(int a, int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

double rnd()
{
    return double(rng()%X)/X;
}

int getRand(int l, int r)
{
    return uniform_int_distribution<int>(l,r)(rng);
}

ll calc(bitset<NUM> &toCheck)
{
    int x=0,y=0;
    for (int i=0;i<n;++i)
    {
        if (toCheck[i]==0)
        {
            x=gcd(x,a[i][0]);
            y=gcd(y,a[i][1]);
        }
        else
        {
            x=gcd(x,a[i][1]);
            y=gcd(y,a[i][0]);
        }
    }
    return (1LL*x*y)/gcd(x,y);
}

void buildFirst()
{
    for (int i=0;i<n;++i)
        ans[i]=getRand(0,1);
    score=calc(ans);
}

void copyAtoB(bitset<NUM> &a, bitset<NUM> &b)
{
    for (int i=0;i<n;++i)
        b[i]=a[i];
}

void makeNew()
{
    copyAtoB(ans,newAns);
    k=uniform_int_distribution<int>(0,n-1)(rng);
    newAns[k]=1-newAns[k];
    newScore=calc(newAns);
    if (newScore>=score||rnd()<exp((newScore-score)/t))
    {
        ans[k]=1-ans[k];
        score=newScore;
    }
}

int main()
{
    int start=clock();
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i][0]>>a[i][1];
    buildFirst();
    while ((clock()-start)/double(CLOCKS_PER_SEC)<1.9)
    {
        t*=0.99999289;
        makeNew();
    }
    //cout<<fixed<<setprecision(10)<<t<<"\n";
    cout<<score<<"\n";
    return 0;
}