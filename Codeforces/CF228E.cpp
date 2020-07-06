#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m;
map<int,vector<pair<int,int>>> edges;

vector<int> fakeVector()
{
    vector<int> v;
    for (int i=0;i<101;++i)
        v.push_back(69);
    return v;
}

int visited[101];

vector<int> checker(int x, int edgeQuality[], bool b)
{
    for (int i=0;i<101;++i)
        visited[i]=0;
    vector<int> edgesHere;
    queue<int> qu;
    vector<int> v;
    qu.push(x);
    int a,flag;
    visited[x]=1;
    while (!qu.empty())
    {
        a=qu.front();
        qu.pop();
        flag=0;
        for (auto u : edges[a])
        {
            edgesHere.push_back(u.second);
            if (!visited[u.first])
            {
                visited[u.first]=1;
                qu.push(u.first);
            }
            if (!edgeQuality[u.second])
                flag=1;
        }
        if (flag)
        {
            if ((a!=x)||b)
            {
                for (auto u : edges[a])
                {
                    edgeQuality[u.second]=1-edgeQuality[u.second];
                }
                v.push_back(a);
            }
        }
    }
    for (auto c : edgesHere)
        if (!edgeQuality[c])
            return fakeVector();
    return v;
}

int done[101];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,c;
    cin>>n>>m;
    vector<int> v;
    vector<int> cur;
    vector<int> w1;
    vector<int> w2;
    int edgeStatus[m];
    int edge1[m];
    int edge2[m];
    for (int i=0;i<m;++i)
    {
        cin>>a>>b>>c;
        edges[a].push_back({b,i});
        edges[b].push_back({a,i});
        edgeStatus[i]=c;
        edge1[i]=c;
        edge2[i]=c;
    }
    queue<int> q;
    for (int i=1;i<=n;++i)
    {
        if (!done[i])
        {
            cur=fakeVector();
            done[i]=1;
            q.push(i);
            while (!q.empty())
            {
                b=0;
                a=q.front();
                q.pop();
                for (auto u : edges[a])
                {
                    if (!done[u.first])
                    {
                        done[u.first]=1;
                        q.push(u.first);
                    }
                    if (!edgeStatus[u.second])
                    {
                        b=1;
                    }
                }
                if (b)
                {
                    w1=checker(a,edge1,0);
                    w2=checker(a,edge2,1);
                    if (sz(w1)<sz(w2)&&sz(w1)<sz(cur))
                    {
                        cur.clear();
                        for (auto u : w1)
                            cur.push_back(u);
                    }
                    else if (sz(w2)<sz(cur))
                    {
                        cur.clear();
                        for (auto u : w1)
                            cur.push_back(u);
                    }
                }
            }
            for (auto u : cur)
                v.push_back(u);
        }
    }
    if (sz(v)>n)
    {
        cout<<"Impossible";
        return 0;
    }
    cout<<sz(v)<<"\n";
    for (auto u : v)
        cout<<u<<" ";
    return 0;
}