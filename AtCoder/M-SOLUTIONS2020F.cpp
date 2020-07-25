#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> up[200001];
vector<int> down[200001];
vector<int> lefto[200001];
vector<int> righto[200001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y,l,r,m=0,ans=1e9,tmp;
    string s;
    cin>>n;
    map<int,vector<int>> upP;
    map<int,vector<int>> downP;
    map<int,vector<int>> leftP;
    map<int,vector<int>> rightP;
    map<int,vector<int>> upM;
    map<int,vector<int>> downM;
    map<int,vector<int>> leftM;
    map<int,vector<int>> rightM;
    for (int i=0;i<n;++i)
    {
        cin>>x>>y>>s;
        if (s[0]=='R')
        {
            righto[y].push_back(x);
            rightM[x-y].push_back(x);
            rightP[x+y].push_back(x);
        }
        if (s[0]=='L')
        {
            lefto[y].push_back(x);
            leftM[x-y].push_back(x);
            leftP[x+y].push_back(x);
        }
        if (s[0]=='U')
        {
            up[x].push_back(y);
            upM[x-y].push_back(x);
            upP[x+y].push_back(x);
        }
        if (s[0]=='D')
        {
            down[x].push_back(y);
            downM[x-y].push_back(x);
            downP[x+y].push_back(x);
        }
    }
    for (int i=0;i<200001;++i)
    {
        sort(down[i].begin(), down[i].end());
        if (sz(down[i]))
            for (int j : up[i])
                if (down[i].back()>j)
                {
                    l=0;r=sz(down[i])-1;
                    while (l<r)
                    {
                        m=l+(r-l)/2;
                        if (down[i][m]>j)
                            r=m;
                        else
                            l=m+1;
                    }
                    tmp=down[i][l]-j;
                    tmp*=5;
                    ans=min(ans,tmp);
                }
    }
    for (int i=0;i<200001;++i)
    {
        sort(lefto[i].begin(), lefto[i].end());
        if (sz(lefto[i]))
            for (int j : righto[i])
                if (lefto[i].back()>j)
                {
                    l=0;r=sz(lefto[i])-1;
                    while (l<r)
                    {
                        m=l+(r-l)/2;
                        if (lefto[i][m]>j)
                            r=m;
                        else
                            l=m+1;
                    }
                    tmp=lefto[i][m]-j;
                    tmp*=5;
                    ans=min(ans,tmp);
                }
    }
    for (int i=-200000;i<=400000;++i)
    {
        sort(leftM[i].begin(), leftM[i].end());
        sort(leftP[i].begin(), leftP[i].end());
        sort(downM[i].begin(), downM[i].end());
        sort(downP[i].begin(), downP[i].end());
        for (auto j : {{rightM[i],leftM[i]},{rightP[i],leftP[i]},{upM[i],downM[i]},{upP[i],downP[i]}})
            if (sz(j.second))
                for (int k : j.first)
                {
                    if (<j.second[0])
                }
    }
    cout<<ans;
    return 0;
}