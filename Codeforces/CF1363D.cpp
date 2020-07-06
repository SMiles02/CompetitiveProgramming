#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> a[1001];

void solve()
{
    int n,k,c,x,y,l,r,maxi;
    string s;
    cin>>n>>k;
    for (int i=1;i<=k;++i)
    {
        cin>>c;
        a[i].clear();
        for (int j=0;j<c;++j)
        {
            cin>>x;
            a[i].push_back(x);
        }
    }
    c=n;
    map<int,int> m;
    if (k==1)
    {
        for (auto j : a[1])
        {
            --c;
            m[j]=1;
        }
        cout<<"? "<<c;
        for (int i=1;i<=n;++i)
            if (!m[i])
                cout<<" "<<i;
        cout<<endl;
        cin>>x;
        cout<<"! "<<x<<endl;
        cin>>s;
        return;
    }
    for (int i=1;i<=k/2;++i)
        for (int j : a[i])
        {
            --c;
            m[j]=1;
        }
    cout<<"? "<<c;
    for (int i=1;i<=n;++i)
        if (!m[i])
            cout<<" "<<i;
    cout<<endl;
    cin>>x;
    m.clear();
    c=n;
    for (int i=k/2+1;i<=k;++i)
        for (int j : a[i])
        {
            --c;
            m[j]=1;
        }
    cout<<"? "<<c;
    for (int i=1;i<=n;++i)
        if (!m[i])
            cout<<" "<<i;
    cout<<endl;
    cin>>y;
    maxi=max(x,y);
    if (x==y)
    {
        cout<<"!";
        for (int i=0;i<k;++i)
            cout<<" "<<maxi;
        cout<<endl;
        cin>>s;
        return;
    }
    if (x<y)
    {
        l=1;r=k/2;
    }
    else
    {
        l=k/2+1;r=k;
    }
    while (1)
    {
        if (l==r)
        {
            m.clear();
            c=n;
            for (int i=l;i<=l;++i)
                for (int j : a[i])
                {
                    --c;
                    m[j]=1;
                }
            cout<<"? "<<c;
            for (int i=1;i<=n;++i)
                if (!m[i])
                    cout<<" "<<i;
            cout<<endl;
            cin>>y;
            cout<<"!";
            for (int i=1;i<l;++i)
                cout<<" "<<maxi;
            cout<<" "<<y;
            for (int i=l+1;i<=k;++i)
                cout<<" "<<maxi;
            cout<<endl;
            cin>>s;
            return;
        }
        m.clear();
        c=0;
        for (int i=l;i<=l+(r-l)/2;++i)
            for (int j : a[i])
            {
                ++c;
                m[j]=1;
            }
        cout<<"? "<<c;
        for (int i=1;i<=n;++i)
            if (m[i])
                cout<<" "<<i;
        cout<<endl;
        cin>>y;
        if (y==maxi)
            r=l+(r-l)/2;
        else
            l=l+(r-l)/2+1;
    }
}

int main()
{
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}