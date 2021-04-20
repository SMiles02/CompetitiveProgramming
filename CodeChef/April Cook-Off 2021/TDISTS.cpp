#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int e,o,s;
    cin>>e>>o;
    s=sqrt(e+o);
    if (s*s!=e+o)
    {
        cout<<"NO\n";
        return;
    }
    //a+b=s
    for (int i=1;i<s;++i)
        if (i*i+(s-i)*(s-i)==e&&i*(s-i)*2==o)
        {
            cout<<"YES\n";
            cout<<s<<"\n";
            for (int j=2;j<=i;++j)
                cout<<j<<" "<<i+1<<"\n";
            for (int j=i+1;j<=s;++j)
                cout<<j<<" 1\n";
            return;
        }
    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}