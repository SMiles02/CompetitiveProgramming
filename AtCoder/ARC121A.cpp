#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

set<int> s[200001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    array<int,3> a[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>a[i][0]>>a[i][1];
        a[i][2]=i;
    }
    vector<int> v;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=2;++j)
            if (s[a[i][2]].count(a[j][2])==0)
            {
                v.push_back(max(abs(a[i][0]-a[j][0]),abs(a[i][1]-a[j][1])));
                s[a[i][2]].insert(a[j][2]);
                s[a[j][2]].insert(a[i][2]);
                //cout<<a[i][2]<<" "<<a[j][2]<<"\n";
                //cout<<max(abs(a[i][0]-a[j][0]),abs(a[i][1]-a[j][1]))<<"\n";
            }
        for (int j=max(3,n-1);j<=n;++j)
            if (s[a[i][2]].count(a[j][2])==0)
            {
                v.push_back(max(abs(a[i][0]-a[j][0]),abs(a[i][1]-a[j][1])));
                s[a[i][2]].insert(a[j][2]);
                s[a[j][2]].insert(a[i][2]);
                //cout<<a[i][2]<<" "<<a[j][2]<<"\n";
                //cout<<max(abs(a[i][0]-a[j][0]),abs(a[i][1]-a[j][1]))<<"\n";
            }
    }
    for (int i=1;i<=n;++i)
        swap(a[i][0],a[i][1]);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=2;++j)
            if (s[a[i][2]].count(a[j][2])==0)
            {
                v.push_back(max(abs(a[i][0]-a[j][0]),abs(a[i][1]-a[j][1])));
                s[a[i][2]].insert(a[j][2]);
                s[a[j][2]].insert(a[i][2]);
                //cout<<a[i][2]<<" "<<a[j][2]<<"\n";
                //cout<<max(abs(a[i][0]-a[j][0]),abs(a[i][1]-a[j][1]))<<"\n";
            }
        for (int j=max(3,n-1);j<=n;++j)
            if (s[a[i][2]].count(a[j][2])==0)
            {
                v.push_back(max(abs(a[i][0]-a[j][0]),abs(a[i][1]-a[j][1])));
                s[a[i][2]].insert(a[j][2]);
                s[a[j][2]].insert(a[i][2]);
                //cout<<a[i][2]<<" "<<a[j][2]<<"\n";
                //cout<<max(abs(a[i][0]-a[j][0]),abs(a[i][1]-a[j][1]))<<"\n";
            }
    }
    sort(v.rbegin(), v.rend());
    cout<<v[1];
    return 0;
}