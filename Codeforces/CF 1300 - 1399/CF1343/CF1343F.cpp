#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
int groups[201];
bool groupNums[201][201];
int groupSizes[201];
int groupMaxi[201];

int doesThisWork(int grups[], bool grupNums[][201], int x)
{
    int cur,su=0;
    int ans[n];
    bool goodies[n+1];
    for (int j=1;j<=n;++j)
    {
        if (grupNums[j][x])
        {
            cur=j;
            break;
        }
    }
    for (int j=1;j<x;++j)
    {
        if (grupNums[cur][j])
        {
            --grups[j];
            goodies[j]=1;
            grupNums[cur][j]=0;
        }
        else
        {
            goodies[j]=0;
        }
    }
    for (int j=x+1;j<=n;++j)
    {
        if (grupNums[cur][j])
        {
            --grups[j];
            goodies[j]=1;
            grupNums[cur][j]=0;
        }
        else
        {
            goodies[j]=0;
        }
    }
    goodies[x]=0;
    ans[0]=x;
    grups[x]=0;
    su=x;
    for (int i=1;i<n-1;++i)
    {
        cur=0;
        for (int j=1;j<=n;++j)
        {
            if (grups[j]==1&&goodies[j])
            {
                cur=j;
                break;
            }
        }
        if (cur==0)
        {
            return 0;
        }
        ans[i]=cur;
        su+=cur;
        for (int j=1;j<=n;++j)
        {
            if (grupNums[j][cur])
            {
                cur=j;
                break;
            }
        }
        for (int j=1;j<ans[i];++j)
        {
            if (grupNums[cur][j])
            {
                --grups[j];
                goodies[j]=1;
                grupNums[cur][j]=0;
            }
            else
            {
                goodies[j]=0;
            }
        }
        for (int j=ans[i]+1;j<=n;++j)
        {
            if (grupNums[cur][j])
            {
                --grups[j];
                goodies[j]=1;
                grupNums[cur][j]=0;
            }
            else
            {
                goodies[j]=0;
            }
        }
        goodies[ans[i]]=0;
    }
    map<int,int> m;
    ans[n-1]=((n*(n+1))/2)-su;
    for (int i=0;i<n;++i)
    {
        if (ans[i]<1||ans[i]>n||m[ans[i]])
        {
            return 0;
        }
        m[ans[i]]=1;
    }
    int maxi,mini;
    for (int i=1;i<n;++i)
    {
        mini=n;
        for (int j=0;j<n;++j)
        {
            if (groupNums[i][ans[j]])
            {
                maxi=j;
                mini=min(mini,j);
            }
        }
        while (maxi-mini+1>groupSizes[i]&&mini+1<n&&!groupNums[i][ans[mini+1]])
        {
            swap(ans[mini],ans[mini+1]);
            ++mini;
        }
        while (maxi-mini+1>groupSizes[i]&&maxi-1>=0&&!groupNums[i][ans[maxi-1]])
        {
            swap(ans[maxi],ans[maxi-1]);
            --maxi;
        }
    }
    for (int i=n-1;i+1;--i)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 1;
}

void solve()
{
    int k,x;
    cin>>n;
    int groups2[n+1];
    bool groupNums2[n+1][201];
    for (int i=1;i<=n;++i)
    {
        groups[i]=0;
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
        {
            groupNums[i][j]=0;
        }
    }
    for (int i=1;i<n;++i)
    {
        cin>>k;
        groupMaxi[i]=1;
        for (int j=0;j<k;++j)
        {
            cin>>x;
            ++groups[x];
            groupNums[i][x]=1;
            groupMaxi[i]=max(groupMaxi[i],x);
        }
        groupSizes[i]=k;
    }
    for (int i=1;i<=n;++i)
    {
        if (groups[i]==1)
        {
            for (int j=1;j<=n;++j)
            {
                groups2[j]=groups[j];
                for (int ind=1;ind<=n;++ind)
                {
                    groupNums2[j][ind]=groupNums[j][ind];
                }
            }
            if (doesThisWork(groups2,groupNums2,i)) return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}