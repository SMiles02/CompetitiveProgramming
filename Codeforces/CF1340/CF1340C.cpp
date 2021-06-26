#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

bitset<10000> done[1000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,g,r,ans=1e9,x,y,z;
    cin>>n>>m;
    int a[m],b[m];
    for (int i=0;i<m;++i)
        cin>>a[i];
    sort(a,a+m);
    for (int i=1;i<m;++i)
        b[i]=a[i]-a[i-1];
    cin>>g>>r;
    deque<array<int,3>> d;
    d.push_back({0,0,0});
    while (!d.empty())
    {
        x=d.front()[0];
        y=d.front()[1];
        z=d.front()[2];
        d.pop_front();
        if (done[x][y])
            continue;
        done[x][y]=1;
        if (y==m-1)
        {
            if (x==0)
                ans=min(ans,z*(g+r)-r);
            else
                ans=min(ans,z*(g+r)+x);
        }
        else if (x+b[y+1]<g&&(!done[x+b[y+1]][y+1]))
            d.push_front({x+b[y+1],y+1,z});
        else if (x+b[y+1]==g&&(!done[0][y+1]))
            d.push_back({0,y+1,z+1});
        if (y)
        {
            if (x+b[y]<g&&(!done[x+b[y]][y-1]))
                d.push_front({x+b[y],y-1,z});
            else if (x+b[y]==g&&(!done[0][y-1]))
                d.push_back({0,y-1,z+1});
        }
    }
    if (ans==1e9)
        ans=-1;
    cout<<ans;
    return 0;
}