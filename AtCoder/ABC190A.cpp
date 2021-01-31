#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    for (int i=0;1;++i)
    {
        if ((i+c)&1)
            if (b--==0)
            {
                cout<<"Takahashi";
                return 0;
            }
        if (((i+c)&1)==0)
            if (a--==0)
            {
                cout<<"Aoki";
                return 0;
            }
    }
    return 0;
}