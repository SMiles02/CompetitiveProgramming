#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mx=0;

void check(int a, int b)
{
    int x=a,y=b;
    for (int i=0;1;++i)
    {
        if (x<y)
            x+=a;
        else if (y<x)
            y+=b;
        else
        {
            if (i>mx)
            {
                cout<<i<<": "<<a<<" "<<b<<"\n";
                mx=i;
            }
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=1;i<=20;++i)
        for (int j=1;j<=20;++j)
            check(i,j);
    return 0;
}