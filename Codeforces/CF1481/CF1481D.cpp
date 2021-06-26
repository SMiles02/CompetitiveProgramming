#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1001;
int n,m;
string s[mn];
vector<int> edges[mn];

void solve()
{
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>s[i];
    if (m&1)
    {
        cout<<"YES\n1 ";
        for (int i=0;i<m;++i)
        {
            if (i&1)
                cout<<"1 ";
            else
                cout<<"2 ";
        }
        cout<<"\n";
        return;
    }
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
            if (s[i][j]==s[j][i])
            {
                cout<<"YES\n";
                for (int k=-1;k<m;++k)
                {
                    if (k&1)
                        cout<<i+1<<" ";
                    else
                        cout<<j+1<<" ";
                }
                cout<<"\n";
                return;
            }
    for (int i=0;i<n;++i)
    {
        edges[i].clear();
        for (int j=0;j<n;++j)
            if (s[i][j]=='a')
                edges[i].push_back(j);
    }
    deque<int> ans;
    for (int i=0;i<n;++i)
        for (int j : edges[i])
            if (!edges[j].empty())
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                ans.push_back(edges[j][0]+1);
                while (sz(ans)<m+1)
                {
                    ans.push_front(ans[1]);
                    ans.push_back(ans[sz(ans)-2]);
                }
                cout<<"YES\n";
                for (int k : ans)
                    cout<<k<<" ";
                cout<<"\n";
                return;
            }
    for (int i=0;i<n;++i)
    {
        edges[i].clear();
        for (int j=0;j<n;++j)
            if (s[i][j]=='b')
                edges[i].push_back(j);
    }
    for (int i=0;i<n;++i)
        for (int j : edges[i])
            if (!edges[j].empty())
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                ans.push_back(edges[j][0]+1);
                while (sz(ans)<m+1)
                {
                    ans.push_front(ans[1]);
                    ans.push_back(ans[sz(ans)-2]);
                }
                cout<<"YES\n";
                for (int k : ans)
                    cout<<k<<" ";
                cout<<"\n";
                return;
            }
    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}