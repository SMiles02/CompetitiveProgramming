#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=0,k;
    vector<int> v;
    vector<int> w;
    map<int,int> m;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        v.push_back(k);
    }
    for (int abc=0;abc<152;++abc)
    {
        k=1;n=sz(v);m.clear();w.clear();
        w.push_back(v[0]);
        m[v[0]]=1;
        for (int i=1;i<n;++i)
        {
            if (w.back()!=v[i])
            {
                w.push_back(v[i]);
                if (!m[v[i]])
                {
                    ++k;
                }
                ++m[v[i]];
            }
        }
        if (k==2)
        {
            cout<<ans+(sz(w)/2)+1;
            return 0;
        }
        v.clear();
        n=sz(w);
        for (int i=0;i<n;++i)
        {
            if (m[w[i]]==1)
            {
                ++ans;
            }
            else
            {
                v.push_back(w[i]);
            }
        }
        if (sz(v)==0)
        {
            cout<<ans;
            return 0;
        }
    }
    return 1;
}