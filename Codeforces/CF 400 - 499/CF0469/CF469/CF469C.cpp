#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    if (n<4)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    if (n%2)
    {
        for (int i=n;i>5;i-=2)
        {
            cout<<i<<" - "<<i-1<<" = 1\n";
            cout<<i-2<<" * 1 = "<<i-2<<"\n";
        }
        cout<<"4 * 5 = 20\n3 - 1 = 2\n2 + 2 = 4\n20 + 4 = 24";
        return 0;
    }
    for (int i=n;i>4;i-=2)
    {
        cout<<i<<" - "<<i-1<<" = 1\n";
        cout<<i-2<<" * 1 = "<<i-2<<"\n";
    }
    cout<<"1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24";
    return 0;
}