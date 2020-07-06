#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
vector<vector<int>> all;
int drops[2000][2];
int total=400000000;

void permutations(vector<int> v)
{
    if (sz(v)==n)
    {
        all.push_back(v);
        return;
    }
    v.push_back(0);
    permutations(v);
    v.pop_back();
    v.push_back(1);
    permutations(v);
}

void scenario(vector<int> v, int x, int y, int a, int b)
{
    int ans=0;
    for (int i=0;i<n;++i)
    {
        if (v[i])
        {
            ans+=abs(x-drops[i][0])+abs(y-drops[i][1]);
            x=drops[i][0];
            y=drops[i][1];
        }
        else
        {
            ans+=abs(a-drops[i][0])+abs(b-drops[i][1]);
            a=drops[i][0];
            b=drops[i][1];
        }
    }
    total=min(total,ans);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,y,a,b;
    cin>>n;
    vector<int> v;
    permutations(v);
    cin>>x>>y>>a>>b;
    for (int i=0;i<n;++i)
    {
        cin>>drops[i][0]>>drops[i][1];
    }
    for (int i=0;i<sz(all);++i)
    {
        scenario(all[i],x,y,a,b);
    }
    cout<<total;
    return 0;
}