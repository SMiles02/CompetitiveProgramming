#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    set<int> s;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        s.insert(k);
    }
    cout<<sz(s);
    return 0;
}