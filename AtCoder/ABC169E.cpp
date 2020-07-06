#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
pair<int,int> a[200000];

int findBig()
{
    int l=1,r=1e9,m,mini,maxi;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        mini=0;maxi=0;
        for (int i=0;i<n;++i)
        {
            if (a[i].second==m)
                ++maxi;
            else if (a[i].second<m)
            {
                ++maxi;
                ++mini;
            }
        }
        if (mini<=n/2&&n/2<=maxi)
            l=m;
        else if (n/2<mini)
            l=m+1;
        else
            r=m-1;
        cout<<mini<<" "<<maxi<<"\n";
        cout<<"cur l r = "<<l<<" "<<r<<"\n";
    }
    cout<<"big = "<<l<<"\n";
    return l;
}

int findSmall()
{
    int l=1,r=1e9,m,mini,maxi;
    while (l<r)
    {
        m=l+(r-l)/2;
        mini=0;maxi=0;
        for (int i=0;i<n;++i)
        {
            if (a[i].second==m)
                ++maxi;
            else if (a[i].second<m)
            {
                ++maxi;
                ++mini;
            }
        }
        if (mini<=n/2&&n/2<=maxi)
            r=m;
        else if (n/2<mini)
            l=m+1;
        else
            r=m-1;
    }
    cout<<"small = "<<l<<"\n";
    return l;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>x>>y;
        a[i]={x,y};
    }
    cout<<findBig()-findSmall()+1;
    return 0;
}