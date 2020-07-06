#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;

bool works(int a[],int splitTill)
{
    map<int,int> m;
    for (int i=0;i<splitTill;++i)
    {
        ++m[a[i]];
    }
    for (int i=1;i<=splitTill;++i)
    {
        if (m[i]!=1)
        {
            return 0;
        }
    }
    m.clear();
    for (int i=splitTill;i<n;++i)
    {
        ++m[a[i]];
    }
    for (int i=1;i<=(n-splitTill);++i)
    {
        if (m[i]!=1)
        {
            return 0;
        }
    }
    return 1;
}

void solve()
{
    int maxi=0,c,d;
    cin>>n;
    map<int,int> m;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        ++m[a[i]];
    }
    for (int i=1;i<n;++i)
    {
        if (m[i])
        {
            maxi=i;
            if (m[i]>2)
            {
                cout<<"0\n";
                return;
            }
        }
    }
    map<int,int> numPres;
    if (maxi>=n)
    {
        cout<<"0\n";
        return;
    }
    if (m[maxi]==2)
    {
        if (works(a,maxi))
        {
            cout<<"1\n"<<maxi<<" "<<maxi<<"\n";
            return;
        }
        cout<<"0\n";
        return;
    }
    c=works(a,maxi);
    d=works(a,n-maxi);
    if (c&&d)
    {
        cout<<"2\n"<<maxi<<" "<<n-maxi<<"\n"<<n-maxi<<" "<<maxi<<"\n";
        return;
    }
    if (c)
    {
        cout<<"1\n"<<maxi<<" "<<n-maxi<<"\n";
        return;
    }
    if (d)
    {
        cout<<"1\n"<<n-maxi<<" "<<maxi<<"\n";
        return;
    }
    cout<<"0\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}