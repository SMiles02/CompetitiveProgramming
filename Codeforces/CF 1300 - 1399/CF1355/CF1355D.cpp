#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,s;
    cin>>n>>s;
    if (n*2>s)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for (int i=1;i<n;++i)
        cout<<"2 ";
    cout<<s-(2*(n-1))<<"\n1";
    return 0;
}