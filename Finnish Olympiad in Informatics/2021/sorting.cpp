#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,a[101],b[101];

void swapper(int x, int y)
{
    //cout<<x<<" "<<y<<"\n";
    swap(a[x],a[y]);
    swap(a[x+1],a[y+1]);
    b[a[x]]=x;
    b[a[y]]=y;
    b[a[x+1]]=x+1;
    b[a[y+1]]=y+1;
    //for (int i=1;i<=n;++i)
    //    cout<<a[i]<<" ";
    //cout<<"\n";
}

void solve()
{
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        b[a[i]]=i;
    }
    for (int i=1;i<=n;++i)
    {
        if (a[i]==i)
            continue;
        if (n-i+1<4)
        {
            cout<<"NO\n";
            return;
        }
        if (b[i]==i+1)
        {
            if (n-i+1<=4)
            {
                cout<<"NO\n";
                return;
            }
            swapper(i,i+2);
        }
        if (b[i]==n)
        {
            if (n-i+1<=4)
            {
                cout<<"NO\n";
                return;
            }
            swapper(n-3,n-1);
        }
        else
            swapper(i,b[i]);
    }
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