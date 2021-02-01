#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int sieve[1000001];

void build()
{
    for (int i=4;i<=1000000;i+=2) sieve[i]=1;
    for (int i=3;i<=1000000;i+=2)
    {
        if (!sieve[i])
        {
            for (int j=i*3;j<=1000000;j+=i) sieve[j]=1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    build();
    int ans=1,cur,inp;
    for (int i=2;i<=1000000;++i)
    {
        if (!sieve[i])
        {
            cur=i;
            while (1)
            {
                cout<<"? "<<cur<<endl;
                cin>>inp;
                if (inp==cur)
                {
                    if (cur*i>1000000)
                    {
                        break;
                    }
                    cur*=i;
                }
                else
                {
                    cur/=i;
                    break;
                }
            }
            ans*=cur;
        }
    }
    cout<<"! "<<ans<<endl;
    return 0;
}