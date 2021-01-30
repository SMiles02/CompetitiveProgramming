#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 7e3+7, INF = 1e4;
int dp[2][mn],ct[2][mn],n,k[2],c;
bitset<mn> done[2];
//0 (unknown)
//1 (win)
//2 (lose)

int getNum(int k)
{
    if (k<1)
        k+=n;
    return k;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cin>>k[0];
    vector<vector<int>> edges;
    vector<int> v1(k[0]);
    for (int& i : v1)
        cin>>i;
    edges.push_back(v1);
    cin>>k[1];
    vector<int> v2(k[1]);
    for (int& i : v2)
        cin>>i;
    edges.push_back(v2);
    queue<array<int,2>> q;
    array<int,2> a;
    q.push({0,1});
    q.push({1,1});
    dp[0][1]=dp[1][1]=2;
    ct[0][1]=ct[1][1]=INF;
    done[0][1]=done[1][1]=1;
    while (!q.empty())
    {
        a=q.front();
        q.pop();
        for (int j : edges[1-a[0]])
        {
            c=getNum(a[1]-j);
            if (!done[1-a[0]][c])
            {
                if (dp[a[0]][a[1]]==2)
                {
                    ct[1-a[0]][c]=INF;
                    dp[1-a[0]][c]=1;
                    done[1-a[0]][c]=1;
                    q.push({1-a[0],c});
                }
                else if (++ct[1-a[0]][c]==k[1-a[0]])
                {
                    dp[1-a[0]][c]=2;
                    done[1-a[0]][c]=1;
                    q.push({1-a[0],c});
                }
            }
        }
    }
    for (int i=2;i<=n;++i)
    {
        if (dp[0][i]==2)
            cout<<"Lose ";
        else if (dp[0][i])
            cout<<"Win ";
        else
            cout<<"Loop ";
    }
    cout<<"\n";
    for (int i=2;i<=n;++i)
    {
        if (dp[1][i]==2)
            cout<<"Lose ";
        else if (dp[1][i])
            cout<<"Win ";
        else
            cout<<"Loop ";
    }
    return 0;
}