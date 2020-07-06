#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,k,ans=0;
    cin>>a>>b;
    if (b>a)
    {
        cout<<0;
        return 0;
    }
    if (b==a)
    {
        cout<<"infinity";
        return 0;
    }
    a-=b;
    k=sqrt(a);
    for (int i=1;i<=k;++i)
    {
        if (!(a%i))
        {
            if (i*i==a)
            {
                if (i>b)
                {
                    ++ans;
                }
            }
            else
            {
                if (i>b)
                {
                    ++ans;
                }
                if ((a/i)>b)
                {
                    ++ans;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}