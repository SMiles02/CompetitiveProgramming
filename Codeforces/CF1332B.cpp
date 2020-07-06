#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,x,k=0;
    map<int,int> done;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>x;
        for (int j=2;j<32;++j)
        {
            if (x%j==0)
            {
                if (!done[j])
                {
                    ++k;
                    done[j]=k; 
                }
                a[i]=done[j];
                break;
            }
        }
    }
    cout<<k<<"\n";
    for (int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}