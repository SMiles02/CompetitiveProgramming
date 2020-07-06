#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[200001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        ++a[k];
    }
    set<pair<int,int>> s;
    for (int i=1;i<200001;++i)
        s.insert({a[i],i});
    while ((*(--(s.end()))).first>2)
    {
        k=(*(--(s.end()))).first;
        x=(*(--(s.end()))).second;
        s.erase((--(s.end())));
        s.insert()
    }
    return 0;
}