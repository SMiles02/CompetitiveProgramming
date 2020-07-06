#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ans=0;
    vector<pair<pair<int,int>,int>> people;
    vector<int> freeRooms;
    multiset<pair<int,int>> departures;
    multiset<pair<int,int>>::iterator it;
    int n,a,b;
    cin>>n;
    int answers[n];
    for (int i=0;i<n;++i)
    {
        cin>>a>>b;
        people.push_back({{a,b},i});
    }
    sort(people.rbegin(), people.rend());
    while (sz(people))
    {
        while (sz(departures))
        {
            it=departures.begin();
            if ((*it).first>=people.back().first.first)
                break;
            freeRooms.push_back((*it).second);
            departures.erase(it);
        }
        if (!sz(freeRooms))
        {
            ++ans;
            freeRooms.push_back(ans);
        }
        answers[people.back().second]=freeRooms.back();
        departures.insert({people.back().first.second,freeRooms.back()});
        freeRooms.pop_back();
        people.pop_back();
    }
    cout<<ans<<"\n";
    for (int i=0;i<n;++i)
        cout<<answers[i]<<" ";
    return 0;
}