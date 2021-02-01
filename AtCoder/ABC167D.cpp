#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int done[200001];
int visited[200001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,pathLength=0,cur=1,recursAt;
    ll k;
    cin>>n>>k;
    int a[n+1];
    int path[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=0;1;++i)
    {
        path[i]=cur;
        if (done[cur])
        {
            pathLength=i;
            recursAt=cur;
            break;
        }
        done[cur]=i+1;
        cur=a[cur];
    }
    //cout<<pathLength<<" "<<recursAt<<"\n";
    if (k<=pathLength)
    {
        cout<<path[k];
        return 0;
    }
    k-=pathLength;
    cur=recursAt;
    //cout<<"test\n";return 0;
    for (int i=0;1;++i)
    {
        if (visited[cur])
        {
            pathLength=i;
            break;
        }
        path[i]=cur;
        visited[cur]=1;
        cur=a[cur];
    }
    cout<<path[k%pathLength];
    return 0;
}