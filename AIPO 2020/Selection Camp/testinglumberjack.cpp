#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define ppii pair<pii,pii>
using namespace std;

void CutDown(int index, int direction);

/**void CutDown(int index, int direction)
{
    cout<<index<<" "<<direction<<"\n";
}**/

void CutPlan(int N, int height[])
{
    int dpLeft[N+1],dpRight[N+1],cur=1,furthest=0,x=0,y=0;
    priority_queue<ppii,vector<ppii>,greater<ppii>> q;
    dpLeft[1]=1;
    q.push({{1,1},{1,0}});
    //cout<<"1 ";
    for (int i=2;i<=N;++i)
    {
        dpLeft[i]=i;
        for (int j=max(i-height[i-1]+1,1);j<i;++j)
            dpLeft[i]=min(dpLeft[i],dpLeft[j]);
        //cout<<dpLeft[i]<<" ";
        q.push({{dpLeft[i],i},{i,0}});
    }
    //cout<<"\n";
    dpRight[N]=N;
    //cout<<N<<"\n";
    q.push({{N,N},{N,1}});
    for (int i=N-1;i;--i)
    {
        dpRight[i]=i;
        for (int j=i+1;j<min(i+height[i-1],N+1);++j)
            dpRight[i]=max(dpRight[i],dpRight[j]);
        q.push({{i,dpRight[i]},{i,1}});
        //cout<<dpRight[i]<<"\n";
    }
    /**for (int i=1;i<=N;++i)
        cout<<dpRight[i]<<" ";
    cout<<"\n";**/
    while (sz(q))
    {
        //cout<<cur<<" "<<furthest<<"\n";
        if (q.top().first.first>cur)
        {
            CutDown(x-1,y);
            cur=furthest+1;
        }
        if (q.top().second.first>=cur)
            if (furthest<q.top().first.second)
            {
                //cout<<q.top().first.first<<" "<<q.top().first.second<<" ";
                //cout<<q.top().second.first<<" "<<q.top().second.second<<"\n";
                furthest=q.top().first.second;
                x=q.top().second.first;
                y=q.top().second.second;
            }
        q.pop();
    }
    if (cur<=N)
        CutDown(x-1,y);
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