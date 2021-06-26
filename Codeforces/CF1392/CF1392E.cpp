#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
ll a[25][25];

void solve()
{
    int x=0,y=0;
    ll k;
    cin>>k;
    while (x+1<n||y+1<n)
    {
        cout<<x+1<<" "<<y+1<<endl;
        if (x==n-1)
            ++y;
        else if (y==n-1)
            ++x;
        else if (a[x+1][y])
        {
            if (k&(a[x+1][y]))
                ++x;
            else
                ++y;
        }
        else
        {
            if (k&(a[x][y+1]))
                ++y;
            else
                ++x;
        }
    }
    cout<<n<<" "<<n<<endl;
    //cout<<"\n";
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin>>n;
    a[0][1]=1;
    for (int j=2;j<n;++j)
        a[0][j]=a[0][j-2]*4;
    for (int i=1;i<n;++i)
        for (int j=0;j<n;++j)
            a[i][j]=a[i-1][j]*2;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cin>>q;
    while (q--)
        solve();
    return 0;
}