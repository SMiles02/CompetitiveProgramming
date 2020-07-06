#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    cout<<c/((a*b)/gcd(a,b));
    return 0;
}