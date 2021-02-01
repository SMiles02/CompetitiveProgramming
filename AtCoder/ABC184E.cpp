#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

vector<pair<pii,int>> edges[2100][2100];
vector<pii> c[26];
bitset<2100> done[2100];

void oneEdge(int x1, int y1, int x2, int y2, int z)
{
    edges[x1][y1].push_back({{x2,y2},z});
}

void edgeAdd(int x1, int y1, int x2, int y2)
{
    oneEdge(x1,y1,x2,y2,1);
    oneEdge(x2,y2,x1,y1,1);
}

void edgeAdd(pii x, pii y)
{
    oneEdge(x.f,x.s,y.f,y.s,1);
    oneEdge(y.f,y.s,x.f,x.s,0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int h,w,x,y,z;
    cin>>h>>w;
    string s[h];
    deque<pair<pii,int>> q;
    for (int i=0;i<h;++i)
    {
        cin>>s[i];
        for (int j=0;j<w;++j)
        {
            if (s[i][j]=='S')
                q.push_back({{i,j},0});
            else if ('a'<=s[i][j]&&s[i][j]<='z')
                c[(s[i][j]-'a')].push_back({i,j});
        }
        for (int j=1;j<w;++j)
            if (s[i][j]!='#'&&s[i][j-1]!='#')
                edgeAdd(i,j,i,j-1);
    }
    for (int j=0;j<w;++j)
        for (int i=1;i<h;++i)
            if (s[i][j]!='#'&&s[i-1][j]!='#')
                edgeAdd(i,j,i-1,j);
    for (int i=0;i<26;++i)
        for (pii j : c[i])
            edgeAdd(j,{2001+i,0});
    while (!q.empty())
    {
        x=q.front().f.f;
        y=q.front().f.s;
        z=q.front().s;
        q.pop_front();
        if (done[x][y])
            continue;
        done[x][y]=1;
        if (x<h&&y<w&&s[x][y]=='G')
        {
            cout<<z;
            return 0;
        }
        for (auto i : edges[x][y])
            if (!done[i.f.f][i.f.s])
            {
                if (i.s==1)
                    q.push_back({{i.f.f,i.f.s},z+1});
                else
                    q.push_front({{i.f.f,i.f.s},z});
            }
    }
    cout<<-1;
    return 0;
}