#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,cur=0,ans=0,here,k;
vector<int> truthTellers;
vector<pair<int,int>> v;
vector<vector<pair<int,int>>> testimonies;
vector<int> testNums;

void checker()
{
    here=0;
    for (int i=0;i<n;++i)
    {
        if (truthTellers[i])
        {
            k=testNums[i];
            for (int j=0;j<k;++j)
            {
                if (testimonies[i][j].second!=truthTellers[testimonies[i][j].first-1])
                {
                    return;
                }
            }
            ++here;
        }
    }
    ans=max(here,ans);
    return;
}

void generate()
{
    if (cur==n)
    {
        checker();
        return;
    }
    truthTellers[cur]=0;
    ++cur;
    generate();
    --cur;
    truthTellers[cur]=1;
    ++cur;
    generate();
    --cur;
    //cout<<"down to "<<cur<<" from "<<cur+1<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,x,y;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>t;
        testNums.push_back(t);
        while (t--)
        {
            cin>>x>>y;
            v.push_back({x,y});
        }
        testimonies.push_back(v);
        truthTellers.push_back(0);
        v.clear();
    }
    generate();
    cout<<ans;
    return 0;
}