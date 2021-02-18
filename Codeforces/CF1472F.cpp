#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,q,x,y;
    cin>>n>>q;
    set<int> b1;
    vector<int> b2={n+1};
    map<int,int> m;
    while (q--)
    {
        cin>>x>>y;
        if (b1.find(y)!=b1.end())
        {
            b1.erase(b1.find(y));
            b2.push_back(y);
        }
        else
        {
            b1.insert(y);
            if ((x+y)&1)
                m[y]=1;
            else
                m[y]=2;
        }
    }
    x=0;
    y=0;
    sort(b2.begin(), b2.end());
    for (int i : b1)
    {
        while (b2[y]<i)
        {
            if (x)
            {
                cout<<"NO\n";
                return;
            }
            ++y;
        }
        if (m[i]==x)
        {
            cout<<"NO\n";
            return;
        }
        x+=m[i];
        if (x==3)
            x=0;
    }
    if (x)
        cout<<"NO\n";
    else
        cout<<"YES\n";
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