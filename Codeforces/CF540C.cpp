#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m;

int score(string s[], int x, int y)
{
    int num=0;
    if (x+1<n)
        if (s[x+1][y]=='.')
            ++num;
    if (y+1<m)
        if (s[x][y+1]=='.')
            ++num;
    if (x-1>=0)
        if (s[x-1][y]=='.')
            ++num;
    if (y-1>=0)
        if (s[x][y-1]=='.')
            ++num;
    return num;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,c,d,x,y;
    cin>>n>>m;
    string s[n];
    for (int i=0;i<n;++i)
        cin>>s[i];
    cin>>a>>b>>c>>d;
    queue<pair<int,int>> q;
    q.push({a,b});
    map<pair<int,int>,int> done;
    done[{a,b}]=1;
    if (a==c&&b==d)
    {
        if (score(s,c-1,d-1))
            cout<<"YES";
        else
            cout<<"NO";
        return 0;
    }
    if (abs(c-a)+abs(d-b)==1)
    {
        if (s[c-1][d-1]=='X'||score(s,c-1,d-1))
            cout<<"YES";
        else
            cout<<"NO";
        return 0;
    }
    while (!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        if (x==c&&y==d)
        {
            if (s[c-1][d-1]=='X'||score(s,c-1,d-1)>1)
                cout<<"YES";
            else
                cout<<"NO";
            return 0;
        }
        if (!done[{x+1,y}]&&x+1<=n&&(s[x][y-1]=='.'||(x+1==c&&y==d)))
        {
            done[{x+1,y}]=1;
            q.push({x+1,y});
        }
        if (!done[{x-1,y}]&&x-1>0&&(s[x-2][y-1]=='.'||(x-1==c&&y==d)))
        {
            done[{x-1,y}]=1;
            q.push({x-1,y});
        }
        if (!done[{x,y+1}]&&y+1<=m&&(s[x-1][y]=='.'||(x==c&&y+1==d)))
        {
            done[{x,y+1}]=1;
            q.push({x,y+1});
        }
        if (!done[{x,y-1}]&&y-1>0&&(s[x-1][y-2]=='.'||(x==c&&y-1==d)))
        {
            done[{x,y-1}]=1;
            q.push({x,y-1});
        }
    }
    cout<<"NO";
    return 0;
}