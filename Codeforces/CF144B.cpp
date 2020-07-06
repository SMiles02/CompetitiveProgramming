#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<pair<pair<int,int>,int>> v;
int ans=0;
map<pair<int,int>,bool> done;

int sq(int x)
{
    return x*x;
}

void check(int x, int y)
{
    if (done[{x,y}])
        return;
    done[{x,y}]=1;
    for (auto i : v)
        if (sq(i.first.first-x)+sq(i.first.second-y)<=sq(i.second))
            return;
    ++ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x1,y1,x2,y2,a,b,c;
    cin>>x1>>y1>>x2>>y2;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>a>>b>>c;
        v.push_back({{a,b},c});
    }
    for (int i=min(x1,x2);i<=max(x1,x2);++i)
    {
        check(i,y1);
        check(i,y2);
    }
    for (int i=min(y1,y2);i<=max(y1,y2);++i)
    {
        check(x1,i);
        check(x2,i);
    }
    cout<<ans;
    return 0;
}