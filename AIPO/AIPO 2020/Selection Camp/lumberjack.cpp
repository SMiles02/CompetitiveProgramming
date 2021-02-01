#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int segLeft[10000000],segRight[10000000],INF=1e9;
int segDP[10000000];

void updateLeft(int i, int cL, int cR, int k, int x)
{
    if (k<cL||cR<k)
        return;
    if (cL==cR)
    {
        segLeft[i]=x;
        return;
    }
    updateLeft((i<<1)+1,cL,cL+((cR-cL)>>1),k,x);
    updateLeft((i<<1)+2,cL+((cR-cL)>>1)+1,cR,k,x);
    segLeft[i]=min(segLeft[(i<<1)+1],segLeft[(i<<1)+2]);
}

int queryLeft(int i, int cL, int cR, int l , int r)
{
    if (r<cL||cR<l)
        return INF;
    if (l<=cL&&cR<=r)
        return segLeft[i];
    return min(queryLeft((i<<1)+1,cL,cL+((cR-cL)>>1),l,r),queryLeft((i<<1)+2,cL+((cR-cL)>>1)+1,cR,l,r));
}

void updateRight(int i, int cL, int cR, int k, int x)
{
    if (k<cL||cR<k)
        return;
    //cout<<i<<" "<<cL<<" "<<cR<<"!!!\n";
    if (cL==cR)
    {
        segRight[i]=x;
        //cout<<"segRight["<<i<<"] updated to "<<x<<"\n";
        return;
    }
    updateRight((i<<1)+1,cL,cL+((cR-cL)>>1),k,x);
    updateRight((i<<1)+2,cL+((cR-cL)>>1)+1,cR,k,x);
    segRight[i]=max(segRight[(i<<1)+1],segRight[(i<<1)+2]);
}

int queryRight(int i, int cL, int cR, int l , int r)
{
    //cout<<i<<": "<<segRight[i]<<"\n";
    if (r<cL||cR<l)
        return 0;
    if (l<=cL&&cR<=r)
        return segRight[i];
    //cout<<max(queryRight((i<<1)+1,cL,cL+((cR-cL)>>1),l,r),queryRight((i<<1)+2,cL+((cR-cL)>>1)+1,cR,l,r))<<" at "<<i<<"\n";
    return max(queryRight((i<<1)+1,cL,cL+((cR-cL)>>1),l,r),queryRight((i<<1)+2,cL+((cR-cL)>>1)+1,cR,l,r));
}

void updateDP(int i, int cL, int cR, int k, int x)
{
    if (k<cL||cR<k)
        return;
    if (cL==cR)
    {
        segDP[i]=x;
        return;
    }
    updateDP((i<<1)+1,cL,cL+((cR-cL)>>1),k,x);
    updateDP((i<<1)+2,cL+((cR-cL)>>1)+1,cR,k,x);
    segDP[i]=min(segDP[(i<<1)+1],segDP[(i<<1)+2]);
}

int queryDP(int i, int cL, int cR, int l , int r)
{
    if (r<cL||cR<l)
        return INF;
    if (l<=cL&&cR<=r)
        return segDP[i];
    return min(queryDP((i<<1)+1,cL,cL+((cR-cL)>>1),l,r),queryDP((i<<1)+2,cL+((cR-cL)>>1)+1,cR,l,r));
}

void CutDown(int index, int direction);

/**void CutDown(int index, int direction)
{
    cout<<index<<" "<<direction<<"\n";
}**/

void CutPlan(int N, int height[])
{
    int dpLeft[N+1],dpRight[N+1];
    for (int i=0;i<10000000;++i)
        segLeft[i]=INF;
    dpLeft[1]=1;
    //cout<<"1 ";
    updateLeft(0,1,N,1,1);
    for (int i=2;i<=N;++i)
    {
        if (height[i-1]==1)
            dpLeft[i]=i;
        else
            dpLeft[i]=queryLeft(0,1,N,max(1,i-height[i-1]+1),i-1);
        updateLeft(0,1,N,i,dpLeft[i]);
        //cout<<dpLeft[i]<<" ";
    }
    //cout<<"\n";
    dpRight[N]=N;
    updateRight(0,1,N,N,N);
    //cout<<N<<"\n";
    for (int i=N-1;i;--i)
    {
        if (height[i-1]==1)
            dpRight[i]=i;
        else
        {
            dpRight[i]=queryRight(0,1,N,i+1,min(N,i+height[i-1]-1));
            //cout<<queryRight(0,1,N,i+1,min(N,i+height[i-1]-1))<<"!!!!\n";
            //cout<<"queryRight made 0 1 "<<N<<" "<<i+1<<" "<<min(N,i+height[i-1]-1)<<" = "<<queryRight(0,1,N,i+1,min(N,i+height[i-1]-1))<<" <--\n";
        }
        updateRight(0,1,N,i,dpRight[i]);
        //cout<<dpRight[i]<<"\n";
    }
    /**for (int i=1;i<=N;++i)
        cout<<dpRight[i]<<" ";
    cout<<"\n";**/
    int dp[N+1],cur=N;
    pair<int,int> move[N+1];
    dp[0]=0;
    for (int i=1;i<=N;++i)
        dp[i]=INF;
    //cout<<"test\n";return;
    for (int i=1;i<=N;++i)
    {
        if (dp[i]>dp[dpLeft[i]-1]+1)
        {
            dp[i]=dp[dpLeft[i]-1]+1;
            move[i]={i,0};
        }
        if (dp[dpRight[i]]>dp[i-1]+1)
        {
            dp[dpRight[i]]=dp[i-1]+1;
            move[dpRight[i]]={i,1};
        }
    }
    /**
    for (int i=1;i<=N;++i)
        cout<<dp[i]<<" "<<move[i].first<<" "<<move[i].second<<"\n";
    **/
    while (cur)
    {
        CutDown(move[cur].first-1,move[cur].second);
        if (move[cur].second)
            cur=move[cur].first-1;
        else
            cur=dpLeft[cur]-1;
    }
}

/**int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int h[n];
    for (int i=0;i<n;++i)
        cin>>h[i];
    CutPlan(n,h);
    return 0;
}**/