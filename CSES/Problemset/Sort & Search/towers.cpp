#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    multiset<int> m;
    multiset<int>::iterator it;
    int n,k;
    cin>>n;
    while (n--)
    {
        cin>>k;
        it=m.upper_bound(k);
        if (it!=m.end())
            m.erase(it);
        m.insert(k);
    }
    cout<<sz(m);
    return 0;
}