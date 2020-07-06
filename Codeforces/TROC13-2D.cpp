#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m;
int s[300][300];
bool done[300][300];

bool ok(int x, int y)
{
    if (0<=x&&x<n&&0<=y&&y<m)
        return 1;
    return 0;
}

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int check(int k)
{
    for (int i=0;i<300;++i)
        for (int j=0;j<300;++j)
            done[i][j]=0;
    int ans=0,a,b,x,y;
    queue<pair<int,int>> q;
    //cout<<"k is "<<k<<"\n";
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (s[i][j]>k&&!done[i][j])
            {
                ++ans;
                q.push({i,j});
                done[i][j]=1;
                //cout<<i<<" "<<j<<" added\n";
                while (!q.empty())
                {
                    a=q.front().first;
                    b=q.front().second;
                    q.pop();
                    //cout<<a<<", "<<b<<" => "<<s[a][b]<<"\n";
                    for (int c=0;c<4;++c)
                    {
                        x=a+dx[c];
                        y=b+dy[c];
                        //cout<<x<<" "<<y<<" !\n";
                        //cout<<ok(x,y)<<" "<<s[x][y]<<">"<<k<<" "<<1-done[x][y]<<"\n";
                        if (ok(x,y)&&s[x][y]>k&&!done[x][y])
                        {
                            //cout<<x<<", "<<y<<" => "<<s[x][y]<<"\n";
                            done[x][y]=1;
                            q.push({x,y});
                        }
                    }
                }
            }
    //cout<<"nya\n";
    //cout<<k<<": "<<ans<<"\n";
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int l=1,r=1,mid;
    cin>>n>>m;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
        {
            cin>>s[i][j];
            r=max(r,s[i][j]);
        }
    while (l<r)
    {
        mid=l+(r-l)/2+1;
        if (check(mid-1)>=check(mid))
            r=mid-1;
        else
            l=mid;
    }
    cout<<max(1,check(l));
    return 0;
}