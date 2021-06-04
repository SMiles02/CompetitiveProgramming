#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=3;i;++i)
    {
        if (n<=i/2)
        {
            if (i&1)
                cout<<"YES\n";
            else
                cout<<"NO\n";
            return 0;
        }
        n-=i/2;
    }
    return 0;
}