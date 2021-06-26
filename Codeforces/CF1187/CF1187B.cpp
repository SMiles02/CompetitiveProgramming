#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,ans;
    string s;
    cin>>n;
    cin>>s;
    vector<vector<int>> v;
    vector<int> cur;
    for (int i=0;i<26;++i)
    {
        v.push_back({});
    }
    for (int i=0;i<n;++i)
    {
        v[s[i]-'a'].push_back(i);
    }
    cin>>m;
    for (int i=0;i<m;++i)
    {
        ans=0;
        cin>>s;
        cur.clear();
        for (int j=0;j<26;++j)
        {
            cur.push_back(0);
        }
        k=sz(s);
        for (int j=0;j<k;++j)
        {
            ++cur[s[j]-'a'];
        }
        for (int j=0;j<26;++j)
        {
            if (cur[j])
            {
                ans=max(ans,v[j][cur[j]-1]);
            }
        }
        cout<<ans+1<<"\n";
    }
    return 0;
}