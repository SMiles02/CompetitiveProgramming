#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,mini=1000000001,maxi=-1,maxDiff=0;
    cin>>n;
    int a[n];
    cin>>a[0];
    for (int i=1;i<n;++i)
    {
        cin>>a[i];
        if (a[i]==-1)
        {
            if (a[i-1]!=-1)
            {
                maxi=max(maxi,a[i-1]);
                mini=min(mini,a[i-1]);
            }
        }
        else if (a[i-1]==-1)
        {
            maxi=max(maxi,a[i]);
            mini=min(mini,a[i]);
        }
        else
        {
            maxDiff=max(maxDiff,abs(a[i]-a[i-1]));
        }
    }
    //cout<<"maxDiff="<<maxDiff<<"\n";
    if (maxi==-1)
    {
        cout<<maxDiff<<" 3\n";
    }
    else
    {
        cout<<max(maxDiff,maxi-(mini+(maxi-mini)/2))<<" "<<mini+(maxi-mini)/2<<"\n";
    }
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