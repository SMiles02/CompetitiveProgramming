#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,l,r,ans=0;
    cin>>n>>k;
    multiset<pair<int,int>> s;
    multiset<int,greater<int>> p;
    while (n--)
    {
        cin>>l>>r;
        s.insert({r,l});
    }
    while (k--)
        p.insert(0);
    while (sz(s))
    {
        if (p.lower_bound((*s.begin()).second)!=p.end())
        {
            ++ans;
            p.erase(p.lower_bound((*s.begin()).second));
            p.insert((*s.begin()).first);
        }
        s.erase(s.begin());
    }
    cout<<ans;
    return 0;
}