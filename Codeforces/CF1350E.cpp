#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m,cur;
bool done[1000][1000];
int swappingStops[1000][1000];
string s[1000];
string t[1000];
vector<pair<int,int>> xy={{0,-1},{0,1},{-1,0},{1,0}};

void check()
{
    int flag;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<m;++j)
        {
            flag=0;
            for (auto b : xy)
                if (0<=b.first+i&&b.first+i<n)
                    if (0<=b.second+j&&b.second+j<m)
                    {
                        //cout<<i<<j<<b.first+i<<b.second+j<<"\n";
                        //cout<<s[i][j]<<" "<<s[b.first+i][b.second+j]<<"\n";
                        if (s[i][j]==s[b.first+i][b.second+j])
                            flag=1;
                    }
            if (flag)
            {
                t[i][j]=('0'+(1-(s[i][j]-'0')));
                if (!done[i][j])
                {
                    done[i][j]=1;
                    swappingStops[i][j]=cur;
                    cout<<i<<" "<<j<<" "<<cur<<"!!!!!\n";
                }
            }
            else
                t[i][j]=s[i][j];
        }
    }
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            s[i][j]=t[i][j];
    /**for (int i=0;i<n;++i)
        cout<<s[i]<<"\n";
    cout<<"----\n";**/
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k,x,y,z;
    cin>>n>>m>>k;
    for (int i=0;i<n;++i)
    {
        cin>>s[i];
        t[i]=s[i];
    }
    for (cur=1;cur<=2000;++cur)
        check();
    while (k--)
    {
        cin>>x>>y>>z;
        --x;--y;
        if (done[x][y])
        {
            cout<<"t\n";
            cout<<z<<" "<<swappingStops[x][y]<<"\n";
            if (z<=swappingStops[x][y])
            {
                cout<<s[x][y]<<"!\n";
            }
            else if ((z-swappingStops[x][y])%2)
                cout<<1-(s[x][y]-'0')<<"!!\n";
            else
                cout<<s[x][y]<<"!!!\n";
        }
        else
            cout<<s[x][y]<<"\n";
    }
    return 0;
}