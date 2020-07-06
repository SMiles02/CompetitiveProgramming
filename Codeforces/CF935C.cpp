#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

double sq(double n)
{
    return n*n;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    double r,a,b,c,d,k,r1,m;
    cin>>r>>a>>b>>c>>d;
    k=sqrt(sq(a-c)+sq(b-d));
    if (k>=r)
    {
        cout<<a<<" "<<b<<" "<<r;
        return 0;
    }
    r1=(k+r)/2;
    m=(d-b)/(c-a);
    
    return 0;
}