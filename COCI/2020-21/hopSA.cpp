#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mn = 1000, X = 2e9;
ll a[mn];
int n,dp[mn][3],score,newScore;
array<array<int,mn>,mn> col,newCol;

double rnd()
{
    return double(rng()%X)/X;
}

void calc(array<array<int,mn>,mn>& e, int& s)
{
    s=0;
    for (int i=0;i<n;++i)
        for (int j=0;j<3;++j)
            dp[i][j]=0;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<3;++j)
            s=max(s,dp[i][j]);
        for (int j=i+1;j<n;++j)
            if (a[j]%a[i]==0)
                dp[j][e[i][j]]=max(dp[j][e[i][j]],dp[i][e[i][j]]+1);
    }
}

int main()
{
    int start = clock();
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
            col[i][j]=uniform_int_distribution<int>(0,2)(rng);
    if (n==1)
        return 0;
    calc(col,score);
    double t = 50;
    int x,y,z;
    while ((clock()-start)/double(CLOCKS_PER_SEC)<0.95)
    {
        t *= 0.9845;
        x = uniform_int_distribution<int>(0,n-2)(rng);
        y = uniform_int_distribution<int>(x+1,n-1)(rng);
        if (x<0)
            continue;
        z=col[x][y];
        while (z==col[x][y])
            z=uniform_int_distribution<int>(0,2)(rng);
        newCol=col;
        newCol[x][y]=z;
        calc(newCol,newScore);
        if (newScore<=score||rnd()<exp((score-newScore)/t))
            col[x][y]=z;
    }
    //cout<<t<<"\n";
    //cout<<"score: "<<score<<"\n\n";
    for (int i=1;i<n;++i)
    {
        for (int j=0;j<i;++j)
            cout<<col[j][i]+1<<" ";
        cout<<"\n";
    }
    return 0;
}

//7 max bound