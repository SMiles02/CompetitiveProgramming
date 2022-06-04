#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    int forwards[n];
    int backwards[n];
    cin>>a[0];
    forwards[0]=1;
    for (int i=1;i<n;++i)
    {
        cin>>a[i];
        if (a[i]<i)
        {
            forwards[i]=0;
        }
        else
        {
            forwards[i]=min(1,forwards[i-1]);
        }
    }
    backwards[n-1]=1;
    for (int i=n-2;i+1;--i)
    {
        if (a[i]<n-i-1)
        {
            backwards[i]=0;
        }
        else
        {
            backwards[i]=min(1,backwards[i+1]);
        }
        if (forwards[i]&&backwards[i])
        {
            cout<<"Yes\n";
            return;
        }
    }
    if (forwards[0]&&backwards[0])
    {
        cout<<"Yes\n";
        return;
    }
    if (forwards[n-1]&&backwards[n-1])
    {
        cout<<"Yes\n";
        return;
    }
    cout<<"No\n";
    /**for (int i=0;i<n;++i)
    {
        cout<<forwards[i]<<" ";
    }
    cout<<"\n";
    for (int i=0;i<n;++i)
    {
        cout<<backwards[i]<<" ";
    }
    cout<<"\n";**/
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