#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    double a,b,c;
    cin>>a>>b>>c;
    a=sqrt(a);
    b=sqrt(b);
    c=sqrt(c);
    cout<<a<<" "<<b<<" "<<c<<"\n";
    cout<<c-a-b<<"\n";
    if (a+b<c)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}