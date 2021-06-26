#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x,ans=3600000,i,cur;
    map<int,vector<int>> m;
    cin>>n>>k;
    while (n--)
    {
        cin>>x;
        i=0;
        while (x)
        {
            m[x].push_back(i);
            ++i;
            x/=2;
        }
        m[0].push_back(i);
    }
    for (int j=0;j<200001;++j)
    {
        if (sz(m[j])>=k)
        {
            sort(m[j].begin(), m[j].end());
            cur=0;
            for (i=0;i<k;++i)
            {
                cur+=m[j][i];
            }
            ans=min(cur,ans);
        }
    }
    cout<<ans;
    return 0;
}