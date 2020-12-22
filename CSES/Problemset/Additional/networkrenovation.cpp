#include <bits/stdc++.h>
using namespace std;

int e[100001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>a>>b;
        ++e[a];
        ++e[b];
    }
    a=0;b=0;
    vector<pair<int,int>> v;
    for (int i=1;i<=n;++i)
        if (e[i]==1)
        {
            if (a)
            {
                v.push_back({a,i});
                a=0;
            }
            else
                a=i;
            if (b==0)
                b=i;
        }
    if (a)
        v.push_back({a,b});
    cout<<v.size()<<"\n";
    for (auto i : v)
        cout<<i.first<<" "<<i.second<<"\n";
    return 0;
}