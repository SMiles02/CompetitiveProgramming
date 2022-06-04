#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,t,l,r;
    pair<int,int> p;
    cin>>n>>m;
    vector<pair<int,int>> sorted;
    vector<pair<int,int>> unsorted;
    vector<pair<int,int>> newSorted;
    while (m--)
    {
        cin>>t>>l>>r;
        if (t)
            sorted.push_back({l,r});
        else
            unsorted.push_back({l,r});
    }
    sort(sorted.rbegin(), sorted.rend());
    while (sz(sorted))
    {
        p=sorted.back();
        sorted.pop_back();
        while (sz(sorted)&&sorted.back().first<=p.second)
        {
            p.second=max(p.second,sorted.back().second);
            sorted.pop_back();
        }
        newSorted.push_back(p);
    }
    int a[n+1];
    int b[n];
    for (int i=1;i<n;++i)
        b[i]=-1;
    a[1]=1e6;
    for (auto i : newSorted)
        for (int j=i.first;j<i.second;++j)
            b[j]=1;
    set<int> s;
    for (int i=2;i<=n;++i)
        a[i]=a[i-1]+b[i-1];
    for (int i=1;i<n;++i)
        if (a[i]>=a[i+1])
            s.insert(i);
    for (auto i : unsorted)
    {
        if (s.lower_bound(i.first)==s.end())
        {
            cout<<"NO";
            return 0;
        }
        if (*(s.lower_bound(i.first))>=i.second)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n";
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
    return 0;
}