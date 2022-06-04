#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x,l,r,m,ans=0;
    cin>>n;
    vector<pair<pair<int,int>,int>> v;
    vector<pair<int,int>> ansVector;
    pair<int,int> p;
    for (int i=0;i<n;++i)
    {
        cin>>p.second>>p.first;
        v.push_back({p,i+1});
    }
    cin>>k;
    vector<pair<int,int>> tables;
    for (int i=0;i<k;++i)
    {
        cin>>x;
        tables.push_back({x,i+1});
    }
    sort(tables.begin(), tables.end());
    sort(v.begin(), v.end());
    while (sz(v))
    {
        if (sz(tables))
        {
            //cout<<v.back().first.first<<" "<<v.back().first.second<<"\n";
            l=0;r=tables.size()-1;
            while (l<r)
            {
                //cout<<"l="<<l<<", r="<<r<<"\n";
                m=l+(r-l)/2;
                if (tables[m].first<v.back().first.second)
                {
                    l=m+1;
                }
                else
                {
                    r=m;
                }
            }
            if (tables[l].first>=v.back().first.second)
            {
                ans+=v.back().first.first;
                ansVector.push_back({v.back().second,tables[l].second});
                tables.erase(tables.begin()+l);
            }
        }
        v.pop_back();
    }
    k=sz(ansVector);
    cout<<k<<" "<<ans<<"\n";
    for (int i=0;i<k;++i)
    {
        cout<<ansVector[i].first<<" "<<ansVector[i].second<<"\n";
    }
    return 0;
}