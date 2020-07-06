#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    set<int> xCo;
    set<int> yCo;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>x>>y;
        xCo.insert(x);
        yCo.insert(y);
    }
    cout<<max((min(sz(xCo),sz(yCo))+1)/2,1);
    return 0;
}