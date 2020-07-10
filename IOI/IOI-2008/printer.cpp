#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int nextL[500000+5][26],depths[500000+5],tot=0;
vector<pair<int,int>> children[500000+5];
bool isEnd[500000+5];
string alpha="abcdefghijklmnopqrstuvwxyz",ans="";

void dfs(int cur)
{
    for (int i=0;i<26;++i)
        if (nextL[cur][i])
        {
            dfs(nextL[cur][i]);
            children[cur].push_back({depths[nextL[cur][i]],i});
            depths[cur]=max(depths[cur],depths[nextL[cur][i]]+1);
        }
    sort(children[cur].begin(), children[cur].end());
}

void addWord()
{
    int cur=0;
    string s;
    cin>>s;
    for (auto c : s)
    {
        if (!nextL[cur][c-'a'])
        {
            ++tot;
            nextL[cur][c-'a']=tot;
        }
        cur=nextL[cur][c-'a'];
    }
    isEnd[cur]=1;
}

void ansBuilder(int cur)
{
    if (isEnd[cur])
        ans+='P';
    for (auto i : children[cur])
    {
        ans+=alpha[i.second];
        ansBuilder(nextL[cur][i.second]);
    }
    if (cur)
        ans+="-";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        addWord();
    dfs(0);
    ansBuilder(0);
    while (sz(ans)&&ans.back()=='-')
        ans.pop_back();
    cout<<sz(ans)<<"\n";
    for (auto c : ans)
        cout<<c<<"\n";
    return 0;
}