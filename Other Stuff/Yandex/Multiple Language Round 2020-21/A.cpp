#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll p,a,b,c;
    cin>>p;
    if (p<3||p==4)
    {
        cout<<"-1\n";
        return 0;
    }
    a=b=c=p/3;
    if (p%3==2)
        ++b;
    if (p%3)
        ++c;
    cout<<a<<" "<<b<<" "<<c<<"\n";
    if (p%2)
        cout<<"1 "<<p/2<<" "<<p/2<<"\n";
    else
        cout<<"2 "<<p/2-1<<" "<<p/2-1<<"\n";
    return 0;
}