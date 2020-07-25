#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,k,l,c;
    cin>>n>>k>>l;
    int a[n+1];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        if (a[i]>l)
        {
            cout<<"No\n";
            return;
        }
    int b[n+1][2];
    for (int i=0;i<n;++i)
    {
        if (a[i]+k<=l)
        {
            b[i][0]=-k;
            b[i][1]=k;
        }
        else
        {
            b[i][0]=a[i]-l;
            b[i][1]=l-a[i];
        }
    }
    a[n]=l-k;
    b[n][0]=-k;
    b[n][1]=k;
    c=b[0][0];
    for (int i=0;i<n;++i)
    {
        //cout<<
        if (a[i+1]+k<=l)
            c=-k;
        else if (c+1<=b[i+1][1])
        {
            if (b[i+1][0]<=c+1)
                ++c;
            else if (b[i+1][0]<=b[i][1]+1)
                c=b[i+1][0];
            else
            {
                cout<<"No\n";
                return;
            }
        }
        else
        {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
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