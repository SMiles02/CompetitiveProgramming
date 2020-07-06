#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

pair<int,int> v[100000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    ll ans=0;
    cin>>n>>m;
    multiset<int> s;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        s.insert(k);
        ans+=k;
    }
    for (int i=0;i<m;++i)
        cin>>v[i].second>>v[i].first;
    sort(v,v+m);
    for (int i=m-1;i>=0;--i)
        for (int j=0;j<v[i].second;++j)
        {
            if (*(s.begin())>=v[i].first)
                break;
            ans+=v[i].first-*(s.begin());
            //cout<<"+"<<v[i].first<<" "<<-*(s.begin())<<"\n";
            s.insert(v[i].first);
            s.erase(s.begin());
        }
    cout<<ans;
    return 0;
}