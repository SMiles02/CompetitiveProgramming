#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n;
    vector<int> p(n),m(n),v;
    cin>>p[0];
    m[0]=p[0];
    for (int i=1;i<n;++i)
    {
        cin>>p[i];
        m[i]=max(m[i-1],p[i]);
    }
    k=n-1;
    while (k>=0)
    {
        while (m[k]!=p[k])
        {
            v.push_back(p[k]);
            --k;
        }
        cout<<p[k--]<<" ";
        while (!v.empty())
        {
            cout<<v.back()<<" ";
            v.pop_back();
        }
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}