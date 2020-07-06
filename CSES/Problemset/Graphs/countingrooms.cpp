#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<pair<int,int>> xy = {{0,-1},{0,1},{-1,0},{1,0}};
bool done[1000][1000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,ans=0;
    pair<int,int> k;
    cin>>n>>m;
    string s[n];
    for (int i=0;i<n;++i)
        cin>>s[i];
    queue<pair<int,int>> q;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (s[i][j]=='.'&&!done[i][j])
            {
                q.push({i,j});
                done[i][j]=1;
                ++ans;
                while (!q.empty())
                {
                    k=q.front();q.pop();
                    for (auto ab : xy)
                        if (ab.first+k.first>=0&&ab.first+k.first<n)
                            if (ab.second+k.second>=0&&ab.second+k.second<m)
                                if (s[ab.first+k.first][ab.second+k.second]=='.'&&!done[ab.first+k.first][ab.second+k.second])
                                {
                                    q.push({ab.first+k.first,ab.second+k.second});
                                    done[ab.first+k.first][ab.second+k.second]=1;
                                }
                }
            }
    cout<<ans;
    return 0;
}