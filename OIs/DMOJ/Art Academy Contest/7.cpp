#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int works(int n)
{
    int zero=0,good=0;
    while (n)
    {
        if (n%10==0)
        {
            ++zero;
        }
        else if (n%10==1)
        {
            if (zero>1)
            {
                return 0;
            }
            if (zero)
            {
                good=1;
            }
        }
        n/=10;
    }
    return good;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=0;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        if (works(i))
        {
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}