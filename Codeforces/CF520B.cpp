#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,i;
    cin>>m>>n;
    for (i=0;n!=m;++i)
    {
        if (n>m&&n%2==0)
            n/=2;
        else
            ++n;
    }
    cout<<i;
    return 0;
}