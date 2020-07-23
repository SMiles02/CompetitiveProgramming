#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool b[2000][2000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,t,p,x,y;
    cin>>n>>t>>p;
    for (int i=0;i<n;++i)
        for (int j=0;j<t;++j)
            cin>>b[i][j];
    int a[t];
    for (int i=0;i<t;++i)
    {
        a[i]=n;
        for (int j=0;j<n;++j)
            a[i]-=b[j][i];
    }
    vector<pair<pair<int,int>,int>> v;
    for (int i=0;i<n;++i)
    {
        x=0,y=0;
        for (int j=0;j<t;++j)
            if (b[i][j])
            {
                x+=a[j];
                ++y;
            }
        v.push_back({{x,y},-(i+1)});
    }
    sort(v.rbegin(), v.rend());
    for (int i=0;i<n;++i)
        if (v[i].second==-p)
            cout<<v[i].first.first<<" "<<i+1<<"\n";
    return 0;
}