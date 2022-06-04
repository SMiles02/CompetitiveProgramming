#include <bits/stdc++.h>
using namespace std;

void print(int l, int r)
{
    for (int i=l;i<=r-2;i+=2)
        cout<<i<<" ";
    for (int i=r-4;i>=l;i-=2)
        cout<<i<<" ";
}

void solve()
{
    int n,x=0;
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        x^=a[i];
    }
    if (x)
    {
        cout<<"NO\n";
        return;
    }
    if (n&1)
    {
        cout<<"YES\n"<<n/2+(n-2)/2<<"\n";
        print(1,n);
        cout<<"\n";
    }
    else
    {
        x=0;
        for (int i=1;i<=n;++i)
        {
            x^=a[i];
            if ((i&1)&&x==0)
            {
                cout<<"YES\n"<<i/2+(i-2)/2+(n-i)/2+(n-i-2)/2<<"\n";
                print(1,i);
                print(i+1,n);
                cout<<"\n";
                return;
            }
        }
        cout<<"NO\n";
    }
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