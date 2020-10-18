#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    set<int> s;
    vector<int> v;
    int k;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (sz(s)<14)
    {
        k=uniform_int_distribution<int>(1,179)(rng);
        if (s.find(k)==s.end())
            v.push_back(k);
        s.insert(k);
    }
    sort(v.begin(),v.end());
    for (int i : v)
        cout<<i<<" ";
    cout<<"\n"<<v[0]<<"\n";
    for (int i=1;i<14;++i)
        cout<<(v[i]^v[i-1])<<"\n";
    return 0;
}