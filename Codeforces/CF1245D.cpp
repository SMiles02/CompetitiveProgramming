#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
vector<pair<int,int>> v;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,y;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>x>>y;
        v.push_back({x,y});
    }
    
    return 0;
}