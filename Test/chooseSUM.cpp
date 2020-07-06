#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,target;
    cin>>n>>target;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for (int x=0;x<n;++x)
    {
        for (int b=x+1;b<n;++b)
        {
            for (int c=b+1;c<n;++c)
            {
                for (int d=c+1;d<n;++d)
                {
                    if (a[x]+a[b]+a[c]+a[d]==target)
                    {
                        cout<<a[x]<<" "<<a[b]<<" "<<a[c]<<" "<<a[d]<<"\n";
                    }
                }
            }
        }
    }
    return 0;
}