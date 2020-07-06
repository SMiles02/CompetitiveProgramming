#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int amounts[4];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,x,y,z,s,t;
    ll ans=0;
    cin>>n>>m>>k;
    vector<pair<int,int>> a;
    vector<pair<int,int>> b;
    vector<pair<int,int>> c;
    vector<pair<int,int>> takenA;
    vector<pair<int,int>> takenB;
    vector<pair<int,int>> takenC;
    vector<pair<int,int>> takenD;
    vector<pair<int,pair<int,int>>> total;
    for (int i=1;i<=n;++i)
    {
        cin>>x>>y>>z;
        if (y&&z)
            total.push_back({x,{0,i}});
        else if (y)
            total.push_back({x,{1,i}});
        else if (z)
            total.push_back({x,{2,i}});
        else
            total.push_back({x,{3,i}});
    }
    sort(total.begin(), total.end());
    for (int i=0;i<m;++i)
    {
        if (total[i].second.first==0)
            takenC.push_back({total[i].first,total[i].second.second});
        else if (total[i].second.first==1)
            takenB.push_back({total[i].first,total[i].second.second});
        else if (total[i].second.first==2)
            takenA.push_back({total[i].first,total[i].second.second});
        else
            takenD.push_back({total[i].first,total[i].second.second});
    }
    for (int i=m;i<n;++i)
    {
        if (total[i].second.first==0)
            c.push_back({total[i].first,total[i].second.second});
        else if (total[i].second.first==1)
            b.push_back({total[i].first,total[i].second.second});
        else if (total[i].second.first==2)
            a.push_back({total[i].first,total[i].second.second});
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());
    while (sz(takenA)+sz(takenC)<k)
    {
        s=-1;
        if (sz(takenB)+sz(takenC)>=k&&sz(takenB))
            if (takenB.back().first>=s)
            {
                s=takenB.back().first;
                t=0;
            }
        if (sz(takenD))
            if (takenD.back().first>=s)
            {
                s=takenD.back().first;
                t=1;
            }
        if (s==-1)
        {
            cout<<-1;
            return 0;
        }
        if (t)
            takenD.pop_back();
        else
            takenB.pop_back();

    }
    for (auto i : takenA)
        ans+=i.first;
    for (auto i : takenB)
        ans+=i.first;
    for (auto i : takenC)
        ans+=i.first;
    for (auto i : takenD)
        ans+=i.first;
    cout<<ans<<"\n";
    for (auto i : takenA)
        cout<<i.second<<" ";
    for (auto i : takenB)
        cout<<i.second<<" ";
    for (auto i : takenC)
        cout<<i.second<<" ";
    for (auto i : takenD)
        cout<<i.second<<" ";
    return 0;
}