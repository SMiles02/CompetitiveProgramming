#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e7+1;
int t,a[10][4],s[10][2];
bitset<mn> composite;
bitset<10> bad;

void check()
{
    for (int i=0;i<t;++i)
    {
        if (s[i][0]>s[i][1])
            bad[i]=1;
        s[i][0]=s[i][1]=0;
    }
}

void sieve()
{
    int x,c;
    for (int i=2;i<mn;i+=2)
    {
        c=0;
        x=i;
        while (!(x&1))
        {
            ++c;
            x>>=1;
        }
        for (int j=0;j<t;++j)
        {
            if (a[j][0]<=i&&i<=a[j][1])
                s[j][0]+=c;
            if (a[j][2]<=i&&i<=a[j][3])
                s[j][1]+=c;
        }
    }
    check();
    for (int i=3;i<mn;i+=2)
        if (!composite[i])
        {
            for (int j=i;j<mn;j+=i)
            {
                composite[j]=1;
                c=0;
                x=j;
                while (!(x%i))
                {
                    ++c;
                    x/=i;
                }
                for (int k=0;k<t;++k)
                {
                    if (a[k][0]<=j&&j<=a[k][1])
                        s[k][0]+=c;
                    if (a[k][2]<=j&&j<=a[k][3])
                        s[k][1]+=c;
                }
            }
            check();
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>t;
    for (int i=0;i<t;++i)
        for (int j=0;j<4;++j)
            cin>>a[i][j];
    sieve();
    for (int i=0;i<t;++i)
    {
        if (bad[i])
            cout<<"NE\n";
        else
            cout<<"DA\n";
    }
    return 0;
}