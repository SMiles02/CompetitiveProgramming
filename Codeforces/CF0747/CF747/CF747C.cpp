#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,su,t,k,d,amount;
    cin>>n>>q;
    int servers[n]={0};
    while (q--)
    {
        cin>>t>>k>>d;
        amount=0;
        for (int i=0;i<n;++i)
        {
            if (servers[i]<t)
            {
                ++amount;
            }
        }
        if (amount<k)
        {
            cout<<"-1\n";
        }
        else
        {
            su=0;
            for (int i=0;k;++i)
            {
                if (servers[i]<t)
                {
                    --k;
                    servers[i]=t+d-1;
                    su+=i+1;
                }
            }
            cout<<su<<"\n";

        }
    }
    return 0;
}