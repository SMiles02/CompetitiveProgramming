#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i) cin>>a[i];
    multiset<int> m;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        m.insert(k);
    }
    multiset <int>::iterator it;
    for (int i=0;i<n;++i)
    {
        it = m.lower_bound(n - a[i]);
        if (it == m.end()) it = m.begin();
        cout << (a[i] + *it) % n << " ";
        m.erase(it);
    }
    return 0;
}