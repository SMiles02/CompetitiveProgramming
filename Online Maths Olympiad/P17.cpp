#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int flag,ans=0;
    for (int i=1;i<1025;++i)
    {
        flag=1;
        for (int j=1;j<=i;j*=2)
        {
            if ((i/j+min(1,i%j))%5==0)
            {
                flag=0;
            }
        }
        if (flag)
        {
            ++ans;
            cout<<i<<"\n";
        }
    }
    cout<<ans;
    return 0;
}