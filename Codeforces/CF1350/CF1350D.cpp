#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[100000];

void solve()
{
    int n,k,flag=1;
    cin>>n>>k;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        if (a[i]==k)
            flag=0;
    }
    if (flag)
    {
        cout<<"no\n";
        return;
    }
    if (n==1)
    {
        cout<<"yes\n";
        return;
    }
    for (int i=0;i<n;++i)
        for (int j=i+1;j<min(i+3,n);++j)
            if (a[i]>=k&&a[j]>=k)
            {
                cout<<"yes\n";
                return;
            }
    cout<<"no\n";
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