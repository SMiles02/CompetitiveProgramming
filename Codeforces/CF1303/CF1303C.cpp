#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<char,vector<char>> edges;
map<char,int> isDone;
string ans;
int num;

void dfs(char cur)
{
    ans+=cur;
    isDone[cur]=1;
    int k=sz(edges[cur]);
    if (k==1)
    {
        ++num;
    }
    for (int i=0;i<k;++i)
    {
        if (!isDone[edges[cur][i]])
        {
            dfs(edges[cur][i]);
        }
    }
}

void solve()
{
    edges.clear();
    isDone.clear();
    map<pair<char,char>,int> m;
    string s,others="";
    cin>>s;
    int n=sz(s);
    for (int i=0;i<n-1;++i)
    {
        if (!m[{s[i],s[i+1]}])
        {
            m[{s[i],s[i+1]}]=1;
            m[{s[i+1],s[i]}]=1;
            edges[s[i]].push_back(s[i+1]);
            edges[s[i+1]].push_back(s[i]);
        }
    }
    for (char c='a';c<='z';++c)
    {
        if (sz(edges[c])>2)
        {
            cout<<"NO\n";
            return;
        }
        if (!isDone[c])
        {
            if (!sz(edges[c]))
            {
                others+=c;
            }
            else if (sz(edges[c])==1)
            {
                ans="";
                num=0;
                dfs(c);
                if (num!=2)
                {
                    cout<<"NO\n";return;
                }
                others+=ans;
            }
        }
    }
    //cout<<"others="<<others<<"\n";
    if (sz(others)!=26)
    {
        cout<<"NO\n";return;
    }
    cout<<"YES\n";
    cout<<others<<"\n";return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}