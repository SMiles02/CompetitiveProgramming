#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int dp[N], vl[10];

void notFirst(int k)
{
    while (k>0)
    {
        if (k<9)
        {
            if (k==2)
                cout<<1;
            if (k==3)
                cout<<7;
            if (k==4)
                cout<<4;
            if (k==5)
                cout<<2;
            if (k==6)
                cout<<0;
            if (k==7)
                cout<<8;
            if (k==8)
                cout<<0<<1;
            return;
        }
        if (k%7)
        {
            cout<<0;
            k-=6;
        }
        else
        {
            cout<<8;
            k-=7;
        }
    }
}

void solve()
{
    int n,m, mn = 2e9, dg = -1;
    cin>>n;
    m=n;
    if (n==6)
        cout<<6;
    else
    {
        for (int i=1;i<10;++i)
            if (vl[i]<=n&&dp[n-vl[i]]<mn)
            {
                mn=dp[n-vl[i]];
                dg=i;
            }
        cout<<dg;
        notFirst(n-vl[dg]);
    }
    cout<<" ";
    if (m&1)
    {
        cout<<7;
        m-=3;
    }
    while (m>0)
    {
        cout<<1;
        m-=2;
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    dp[1] = 1e9;
    for (int i=2;i<8;++i)
        dp[i]=1;
    dp[8]=2;
    for (int i=9;i<N;++i)
        dp[i]=dp[i-7]+1;
    vl[0]=7;
    vl[1]=2;
    vl[2]=5;
    vl[3]=5;
    vl[4]=4;
    vl[5]=5;
    vl[6]=6;
    vl[7]=3;
    vl[8]=7;
    vl[9]=6;
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}