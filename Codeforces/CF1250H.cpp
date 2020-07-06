#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void printer(string k, int n)
{
    for (int i=0;i<n;++i)
    {
        cout<<k;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,k;
    cin>>t;
    vector<pair<int,string>> v;
    while (t--)
    {
        for (int i=0;i<10;++i)
        {
            cin>>k;
            v.push_back(make_pair(k,to_string(i)));
        }
        sort(v.begin(),v.end());
        if (v[0].second=="0")
        {
            if (v[0].first==v[1].first)
            {
                swap(v[0],v[1]);
            }
            else
            {
                cout<<1;
            }
        }
        printer(v[0].second,v[0].first+1);
        cout<<"\n";
        v.clear();
    }
    return 0;
}