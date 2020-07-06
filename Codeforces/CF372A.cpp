#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x=0,ans=0;
    cin>>n;
    vector<int> v;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        v.push_back(k);
    }
    vector<int> w;
    sort(v.begin(), v.end());
    while (sz(w)<n/2)
    {
        w.push_back(v.back());
        v.pop_back();
    }
    while (sz(w))
    {
        if (w.back()>=2*v[x])
        {
            ++x;
            ++ans;
        }
        //cout<<w.back()<<"\n";
        w.pop_back();
    }
    cout<<n-ans;
    return 0;
}