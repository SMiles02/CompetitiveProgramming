#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m,isTrue=0;
vector<string> v;
map<pair<int,int>,int> done;

void dfs(int x, int y)
{
    //cout<<x<<" "<<y<<"\n";
    done[make_pair(x,y)]=1;
    int score=0;
    if (y)
    {
        if (v[x][y]==v[x][y-1])
        {
            if (done[make_pair(x,y-1)])
            {
                ++score;
            }
            else
            {
                //cout<<"test1\n";
                dfs(x,y-1);
            }
        }
    }
    if (x)
    {
        if (v[x][y]==v[x-1][y])
        {
            if (done[make_pair(x-1,y)])
            {
                ++score;
            }
            else
            {
                //cout<<"test1\n";
                dfs(x-1,y);
            }
        }
    }
    if (x<n-1)
    {
        if (v[x][y]==v[x+1][y])
        {
            if (done[make_pair(x+1,y)])
            {
                ++score;
            }
            else
            {
                //cout<<"test1\n";
                dfs(x+1,y);
            }
        }
    }
    if (y<m-1)
    {
        if (v[x][y]==v[x][y+1])
        {
            if (done[make_pair(x,y+1)])
            {
                ++score;
            }
            else
            {
                //cout<<"test1\n";
                dfs(x,y+1);
            }
        }
    }
    if (score>1)
    {
        isTrue=1;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    string s;
    for (int i=0;i<n;++i)
    {
        cin>>s;
        v.push_back(s);
    }
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<m;++j)
        {
            if (!done[{i,j}])
            {
                dfs(i,j);
            }
        }
    }
    if (isTrue)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}