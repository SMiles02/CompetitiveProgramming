#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,n,k;
    cin>>x>>n;
    multiset<int,greater<int>> s;
    s.insert(x);
    set<pair<int,int>> regions;
    pair<int,int> p;
    regions.insert({0,x});
    while (n--)
    {
        cin>>k;
        p=(*(--(regions.upper_bound({k,0}))));
        regions.erase(p);
        s.erase(s.lower_bound(p.second-p.first));
        regions.insert({p.first,k});
        s.insert(k-p.first);
        regions.insert({k,p.second});
        s.insert(p.second-k);
        cout<<(*(s.begin()))<<" ";
    }
    return 0;
}